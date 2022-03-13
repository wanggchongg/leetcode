package main

func reverseWords(s string) string {
	var ba = []byte(s)
	reverse(ba)

	for i := 0; i <= len(ba); i++ {
		for j := i + 1; j <= len(ba); j++ {

		}
	}
	return string(ba)
}

func reverse(ba []byte) {
	for i,j := 0, len(ba)-1; i < j; i, j = i+1, j-1 {
		ba[i], ba[j] = ba[j], ba[i]
	}
}
