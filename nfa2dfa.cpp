#include<bits/stdc++.h>
using namespace std;
#define nl <<"\n"
string removeDuplicates(string str);
int main()
{
	int noOfStates,noOfInputSymbols;
	cin>>noOfStates;
	cin>>noOfInputSymbols;

	vector<pair<string,pair<char,string> > > nfa;
	for (int i = 0; i <noOfStates*noOfInputSymbols; i++)
		{
			string intialState,finalState;
			char symbol;
			cin>>intialState;
			cin.ignore();
			cin>>symbol;
			cin.ignore();
			cin>>finalState;

			nfa.push_back(make_pair(intialState,make_pair(symbol,finalState)));

		}	

		vector<pair<string,pair<char,string> > > dfa;
		set<string> visited;

		dfa.push_back(make_pair(nfa[0].first,make_pair(nfa[0].second.first,nfa[0].second.second)));
		dfa.push_back(make_pair(nfa[1].first,make_pair(nfa[1].second.first,nfa[1].second.second)));

		visited.insert(nfa[0].first);
		int n =1;
	for(int i=0;i<=n;i++)
	{
			if(dfa[i].second.second!="0"){
				if(visited.find(dfa[i].second.second)== visited.end())
				{
					visited.insert(dfa[i].second.second);

					string random = dfa[i].second.second;
					//cout<<random nl;
					string resA="",resB="";
					for(int j=0;random[j]!='\0';j++)
					{
						for(int k=0;k<nfa.size();k++)
						{
							if(random[j]==nfa[k].first[0]&& nfa[k].second.first=='a'&& nfa[k].second.second!="0")
							{
								resA = resA + nfa[k].second.second;
								break;
							}

					
						}

						for(int k=0;k<nfa.size();k++)
						{
							if(random[j]==nfa[k].first[0]&& nfa[k].second.first=='b'&& nfa[k].second.second!="0")
							{
								resB = resB + nfa[k].second.second;
								break;
							}
						}
					}
					
					string rA  = removeDuplicates(resA);
					dfa.push_back(make_pair(dfa[i].second.second,make_pair('a',rA)));

					string rB = removeDuplicates(resB);

					dfa.push_back(make_pair(dfa[i].second.second,make_pair('b',rB)));
					n = n+2;
				}
			}
	}
cout<<"Result\n";
	for(int i=0;i<dfa.size();i++)
	{
		cout<<dfa[i].first<<"  "<<dfa[i].second.first<<"  "<<dfa[i].second.second nl;
	}
	
	
}

string removeDuplicates(string str)
{
	 sort(str.begin(), str.end()); 
  
    auto res = unique(str.begin(), str.end()); 
  
    return (string(str.begin(), res) );
      
}	