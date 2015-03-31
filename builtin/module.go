package pongo

func (controller Controller) Model(query string) string {
	return query
}

func (controller Controller) Session(key string, value string) string {
	return "Session values"
}

func (controller Controller) Cookie(key string, value string) string {
	return "Cookie values"
}

func (controller Controller) Translate(word string) string {
	return "ABC"
}