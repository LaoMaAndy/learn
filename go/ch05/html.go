//html
package html

type Node struct {
	Type 			NodeType
	Data			string
	Attr			[]Attribute
	FirstChild, NextSibling *Node
}

type NodeType int32 

const (
	ErrorNode 		NodeType = itoa
	TextNode
	DocumentNode
	ElementNode
	CommentNode
	DoctypeNode
)

type Attribute struct {
	Key, Val string
}

func Parse(r, io.Reader) (*Node, error)
