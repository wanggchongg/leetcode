package main

//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。
//实现 LRUCache 类：
//
//LRUCache(int capacity) 以正整数作为容量capacity 初始化 LRU 缓存
//int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
//void put(int key, int value)如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//
//进阶：你是否可以在O(1) 时间复杂度内完成这两种操作？
//
//
//示例：
//
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2)
//lRUCache.put(1, 1) // 缓存是 {1=1}
//lRUCache.put(2, 2) // 缓存是 {1=1, 2=2}
//lRUCache.get(1)    // 返回 1
//lRUCache.put(3, 3) // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2)    // 返回 -1 (未找到)
//lRUCache.put(4, 4) // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1)    // 返回 -1 (未找到)
//lRUCache.get(3)    // 返回 3
//lRUCache.get(4)    // 返回 4
//
//提示：
//
//1 <= capacity <= 3000
//0 <= key <= 3000
//0 <= value <= 104
//最多调用 3 * 104 次 get 和 put
//
//来源：力扣（LeetCode）
//链接：https: //leetcode-cn.com/problems/lru-cache
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

type lruNode struct {
	next  *lruNode
	key   int
	value int
}

type LRUCache struct {
	head     *lruNode
	tail     *lruNode
	capacity int
	used     int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		head:     nil,
		tail:	  nil,
		capacity: capacity,
		used:     0,
	}
}
func (lc *LRUCache) Get(key int) int {
	if tmp := lc.searchNode(key); tmp != nil {
		lc.moveToTail(tmp)
		return tmp.value
	}

	return -1
}

func (lc *LRUCache) Put(key int, value int)  {
	if tmp := lc.searchNode(key); tmp != nil {
		tmp.value = value
		lc.moveToTail(tmp)
		return
	}

	lc.addNode(key, value)
	if lc.used > lc.capacity {
		lc.delNode()
	}

	return
}

func (lc *LRUCache) addNode(key int, value int) {
	node := &lruNode{
		next:  nil,
		key:   key,
		value: value,
	}

	if lc.tail == nil {
		lc.head, lc.tail = node, node
	} else {
		lc.tail.next = node
		lc.tail = node
	}

	lc.used++
}

func (lc *LRUCache) delNode() {
	if lc.tail == nil {
		return
	}

	lc.head = lc.head.next
	lc.used--
}

func (lc *LRUCache) searchNode(key int) *lruNode {
	if lc.tail == nil {
		return nil
	}

	tmp := lc.head
	for tmp != nil {
		if tmp.key == key {
			return tmp
		}
		tmp = tmp.next
	}

	return nil
}

func (lc *LRUCache) moveToTail(node *lruNode) {
	if lc.tail == node {
		return
	}

	if lc.head == node {
		lc.head = node.next
	} else {
		tmp := lc.head
		for tmp != nil {
			if tmp.next == node {
				tmp.next = node.next
				break
			}
			tmp = tmp.next
		}
	}

	node.next = nil
	lc.tail.next = node
	lc.tail = node
}