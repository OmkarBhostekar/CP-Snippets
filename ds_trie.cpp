class Node{
	public:
		bool flag;
		vector<Node*> Links;
	Node(){
		Links.resize(26, NULL);
		flag = false;
	}
	int containKey(char ch){
		return Links[ch - 'a'] != NULL;
	}
	void putKey(char ch, Node* root){
		Links[ch - 'a'] = root;
	}
	int getEnd(){
		return flag;
	}
	void setEnd(){
		flag = true;
	}
};
class Trie {
	public:
		Node* root;
		Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node* temp = root;
		for(auto it: word){
			if(temp->containKey(it) == false){
				temp->putKey(it, new Node());
			}
			temp = temp->Links[it - 'a'];
		}
		temp->setEnd();
	}
	bool search(string word) {
		Node* temp = root;
		for(auto it: word){
			if(temp->containKey(it) == false) return false;
			temp = temp->Links[it - 'a'];
		}
		return temp->getEnd();
	}
	bool startsWith(string prefix) {
		Node* temp = root;
		for(auto it: prefix){
			if(temp->containKey(it) == false) return false;
				temp = temp->Links[it - 'a'];
			}
		return true;
	}
};