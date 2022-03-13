package structures

func SliceIntEqual(a, b []int) bool {
	if (a == nil) != (b == nil) {
		return false
	}

	if len(a) != len(b) {
		return false
	}

	for key, val := range a {
		if val != b[key] {
			return false
		}
	}

	return true
}