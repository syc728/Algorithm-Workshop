#include <iostream>
#include <cstring>

using namespace std;

const int num = 10;
const int maxn = 100005;

struct node
{
	bool flag;
	node *nxt[num];
	node()
	{
		flag = false;
		memset(nxt, 0, sizeof(num));
	}
}tnode[maxn];

int ct;

bool insert(node *root, string s)
{
	node *cur = root;
	int len = s.size();
	for(int i=0;i<len;i++)
	{
		int index = s[i] - '0';
		if(cur->nxt[index] == NULL)
		{
			node *tmp = &tnode[ct++];
			cur->nxt[index] = tmp;
		}
		else if(cur->nxt[index]->flag)	return false;
		cur = cur->nxt[index];
	}
	cur->flag = true;
	for(int i = 0;i<num;i++)
		if(cur->nxt[num])	return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while(t--)
	{
		memset(tnode, 0, sizeof(tnode));
		node *root = &tnode[0];
		ct = 1;
		cin >> n;
		bool flag = true;
		string s;
		while(n--)
		{
			cin >> s;
			if(insert(root, s))
				flag = true;
			else
			{	flag = false; break; }
		}
		
		if(n > 0) while(n--) cin >> s;	
		(flag) ? (cout << "YES") : (cout << "NO");
		cout << "\n";
	}
	return 0;
}
