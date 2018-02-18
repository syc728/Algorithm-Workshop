#include <iostream>
#include <cstring>

using namespace std;

const int num = 26;

struct node
{
	node *next[num];
	node()
	{
		memset(next, 0, sizeof(next));
	}
};

class Trie
{
public:
	Trie() { root = new node(); }
	void insert(string word);
	bool search(string word);
	void del(node *delNode);

private:
	node *root;
};

void Trie::insert(string word)
{
	node *cur = root;
	for(unsigned int i=0;i<word.size();i++)
	{
		int index = word[i] - 'a';
		if(cur->next[index] == NULL)
		{
			node *tmp = new node();
			cur->next[index] = tmp;
		}
		cur = cur->next[index];
	}
}

bool Trie::search(string word)
{
	node *cur = root;
	unsigned int i = 0;
	while(i < word.size() && cur)
	{
		cur = cur->next[word[i] - 'a'];
		i++;
	}
	
	return cur != NULL;
}

void Trie::del(node *delNode)
{
	for(int i=0;i<num;i++)
		if(delNode->next[i] != NULL)
			del(delNode->next[i]);
	delete delNode;
}

int main()
{
	string wordBag[] = { "pot", "potato", "pottery", "tattoo", "tempo" };
	Trie t;
	
	for(int i=0;i<5; i++)
		t.insert(wordBag[i]);
	
	cout << t.search("wer") << endl;
	
	return 0;
}
