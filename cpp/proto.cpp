#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/tokenizer.h>
#include <google/protobuf/compiler/parser.h>
#include <google/protobuf/descriptor_database.h>
#include "base/common/base.h"
#include "base/common/logging.h"
#include "base/strings/string_split.h"

DEFINE_string(proto_file_path, "", "proto descriptor file path");
DEFINE_string(proto_message_name, "", "proto message name");

class ProtoReader {
 public:
  ProtoReader(const std::string& paths) {
    std::vector<std::string> proto_files;
    base::SplitString(paths, ";", &proto_files);
    for (int i = 0; i < (int)proto_files.size(); ++i) {
      google::protobuf::FileDescriptorProto desc;
      GetMessageTypeFromProtoFile(proto_files[i], &desc);
      if (!database_.Add(desc)) {
        LOG(FATAL) << "Cannot add proto file to database: " << proto_files[i];
      }
    }
    pool_ = new google::protobuf::DescriptorPool(&database_);
  }
  ~ProtoReader() {
    if (pool_) {
      delete pool_;
      pool_ = NULL;
    }
  }

  void GetMessageTypeFromProtoFile(const std::string& path,
                                   google::protobuf::FileDescriptorProto* desc_proto) {
    using namespace google::protobuf;
    using namespace google::protobuf::io;
    using namespace google::protobuf::compiler;
    FILE* proto_file = fopen(path.c_str(), "r");
    if (proto_file == NULL) {
      LOG(FATAL) << "Cannot open .proto file: " << path;
    }
    FileInputStream proto_input_stream(fileno(proto_file));
    Tokenizer tokenizer(&proto_input_stream, NULL);
    Parser parser;
    if (!parser.Parse(&tokenizer, desc_proto)) {
      LOG(FATAL) << "Cannot parse .proto file:" << path;
    }
    fclose(proto_file);
    if (!desc_proto->has_name()) {
      desc_proto->set_name(path);
    }
  }
  void PrintDataFile(const std::string& data,
                     const std::string& message_name) {
    const google::protobuf::Descriptor* message_desc = pool_->FindMessageTypeByName(message_name);
    if (message_desc == NULL) {
      LOG(FATAL) << "Cannot get message descriptor of message: " << message_name;
    }
    std::cout << message_desc->DebugString();
  }
 private:
  google::protobuf::DescriptorPool* pool_;
  google::protobuf::SimpleDescriptorDatabase database_;
};

// void PrintDataFile(const std::string& data,
//                    const google::protobuf::FileDescriptorProto& desc_proto,
//                    const std::string& message_name) {
//   // google::protobuf::DynamicMessageFactory factory;
//   // const google::protobuf::Message* prototype_msg = factory.GetPrototype(message_desc);
//   // if (prototype_msg == NULL) {
//   //   LOG(FATAL) << "Cannot create prototype message from message descriptor";
//   // }
//   // google::protobuf::Message* mutable_msg = prototype_msg->New();
//   // if (mutable_msg == NULL) {
//   //   LOG(FATAL) << "Failed in prototype_msg->New(); to create mutable message";
//   // }
//   // if (!mutable_msg->ParseFromString(data)) {
//   //   LOG(FATAL) << "Failed to parse value";
//   // }
//   // std::cout << mutable_msg->DebugString();
//   // delete mutable_msg;
// }

int main(int argc, char* argv[]) {
  base::InitApp(&argc, &argv, "test");
  ProtoReader reader(FLAGS_proto_file_path);
  reader.PrintDataFile("", FLAGS_proto_message_name);
}
