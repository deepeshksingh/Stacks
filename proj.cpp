#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX_CHAR 26
#define ull unsigned long long int

// Utility method to return integer index
// of character 'c'
int toNum(char c)
{
	return (c - 'a');
}

using namespace std;

void reverse(char *str)
{
	if(*str)
	{
		reverse(str+1);
		printf("%c", *str);
	}
}

bool isAlpha(char x)
{
	if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <='z'))
	{
		return true;
	}
	return false;
}

void ReverseSpl(char *test)
{
	int l,r;
	char temp;
	l = 0; r = strlen(test)-1;
	while(l < r)
	{
		if(!isAlpha(test[l])) l++;
		else if(!isAlpha(test[r])) r--;
		else
		{
			temp = test[r];
			test[r] = test[l];
			test[l] = temp;
			l++;
			r--;
		}
	}	
}

char *removeDupsSorted(char *dup)
{
	int l = 1 ; int r = 1;
	while(*(dup+r))
	{
		//geeksforgeeks => eeeefggkkorss
		if(*(dup+r) != *(dup+r-1))
		{
			*(dup+l) = *(dup+r);
			l++;
		}
		r++;
	}
	*(dup+l)='\0';
	return dup;
}

void removeDuplicates(char *dup)
{
	int n = strlen(dup);
	sort(dup,dup+n);
	cout<<"Duplicate removed ::" <<removeDupsSorted(dup)<<endl;
}

char* removeDupHash(char *str)
{
	bool hash[256] = {0};
	int l = 0; int r = 0;
	int temp;
	while(*(str+r))
	{
		temp = *(str+r);
		if(hash[temp] == 0)
		{
			hash[temp] = 1;
			*(str+l) = *(str+r);
			l++;
		}
		r++;
	}
	*(str+l) = '\0';
	return str;
}

void maxOccurChar(char *s3)
{
	int max[256] = {0};
	int len = strlen(s3);
	for(int i=0;i<len;i++)
		max[s3[i]]++;
	
	int final = -1; char char_final;
	for(int j=0;j<len;j++)
	{
		if(final < max[s3[j]])
		{
			final = max[s3[j]];
			char_final = s3[j];
		}
	}
	cout<<" Final answer = "<<char_final<<"::Freq::"<<final<<endl;
}

struct data
{
	int count;
	int index;	
};

void kthNonRepeat(char *str,int k)
{
	struct data test[256] = {0,0};
	int index[256];
	for(int i=0; i<256; i++) index[i] = 9;

	for(int j=0; j<strlen(str);j++)
	{
		test[str[j]].count++;
		if(test[str[j]].count == 1) 
		{
			test[str[j]].index=j;
			index[str[j]]=j;
		}
		if(test[str[j]].count == 2)
		{
			index[str[j]]=9;
		}	
	}
	
	int result = 25699;
	for(int i=0;i<256;i++)
	{
		if(test[i].count == 1 && (result > test[i].index))
		{
			result = test[i].index;
			cout<<i;
		}
	}
	
	sort(index, index+256);
	
	if(index[k-1] != 0) cout <<" Kth non repeating is ::"<<index[k-1]<<endl;
	else cout<<"Not found non repeating kth smallest"<<endl;
	
	cout<<"First non repeating char ::"<<str[result]<<endl;
}

int countSubs(char *str)
{
	int result=0;
	int count[26]={0};
	
	int len = strlen(str);
	
	for(int i=0;i<len;i++)
		count[(str[i]-'a')]++;
	
	for(int i=0;i<26;i++)
	{
		result+=(count[i]*(count[i]+1))/2;
	}
	
	return result;
}

char maxRepeating(string str)
{
//	aaaabbaaccde
	int count=0;
	int max=0;
	int str_int;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == str[i+1])
		{
			count = count+1;
		}
		else
			count = 1;
			
		if(count > max)
		{
			max = count;
			str_int = i;
		}
	}	
	return str[str_int];
}

int numStringLen(int n)
{
	int temp = n*(n-1);
	return 2*n+temp+temp/2+(temp*(n-2))/2+1;	
}

string getKey(string &str)
{
    bool visited[26] = { false };
    for (int j = 0; j < str.length(); j++)
        visited[str[j] - 'a'] = true ;
    string key = "";
    for (int j=0; j < 26; j++)
        if (visited[j])
            key = key + (char)('a'+j);
    return key;
}

void wordsWithSameCharSet(string words[], int n1)
{
	bool visited[26]={false};
	unordered_map<string,vector<int>> Hash;
	string key;
	for(int i=0;i<n1;i++)
	{
		key = getKey(words[i]);
		Hash[key].push_back(i);
	}
	
	for(auto itr=Hash.begin();itr!=Hash.end();itr++)
	{
		for(auto j=(*itr).second.begin();j!=(*itr).second.end();j++)
			cout<< " " << words[(*j)];
		cout<<endl;
	}	
}

int countOfAnagramSubstring(string str)
{
	int N = str.length();

	// To store counts of substrings with given
	// set of frequencies.
	map<vector<int>, int> mp;

	// loop for starting index of substring
	for (int i=0; i<N; i++)
	{
		vector<int> freq(MAX_CHAR, 0);

		// loop for length of substring
		for (int j=i; j<N; j++)
		{
			// update freq array of current
			// substring
			freq[toNum(str[j])]++;

			// increase count corresponding
			// to this freq array
			mp[freq]++;
//			cout<<"MP::"<<mp[freq]<<endl;
		}
	}
	
	// loop over all different freq array and
	// aggregate substring count
	int result = 0;
	for (auto it=mp.begin(); it!=mp.end(); it++)
	{
		int freq = it->second;
		result += ((freq) * (freq-1))/2;
	}
	return result;
}

int evenNumSubstring(char *str)
{
	int result=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(*(str+i)%2==0) result = result+i+1;
	}
	return result;
}

int minStringValue(string str, int k)
{
	int result =0;
	int count[26]={0};
	if(k >= str.length()) return -1;
	for(int i=0;i<str.length();i++)
	{
		count[str[i]-'a']++;
	}
	
	priority_queue<int> Pq;
	for(int i=0;i<26;i++)
	{
		Pq.push(count[i]);
	}
	
	int temp;
	while(k)
	{
		temp=Pq.top();
		temp = temp-1;
		Pq.pop();
		Pq.push(temp);
		k--;
	}
	
	while(!Pq.empty())
	{
		temp = Pq.top();
		result += temp*temp;
		Pq.pop();
	}
	return result;
}

char * removeDirtyChars(char *str,char* mask_str)
{
// 	geeksforgeeks 
//  mask

	int count[26] = {0};
	
	for(int i=0;i<strlen(mask_str);i++) count[mask_str[i]-'a']++;
	
	char temp;
	int l=0;int r=0;
	for(r=0;r<strlen(str);r++)
	{
		if(count[str[r]-'a']==0) 
		{
			str[l]=str[r];
			l++;	
		}
	}
	str[l]='\0';

	return str;
}


void print_anagrams(string s[],int size) {
	map<string,vector<int>> m;
	map<string,vector<int>>::iterator mit;
	vector<int>::iterator vit;
	for(int i=0;i<size;i++)
	{
		string si=s[i];
//		cout<<"STRING::"<<si<<endl;
		sort(si.begin(),si.end());
//		cout<<"INSERTING::"<<si<<"::I::"<<i<<endl;
		m[si].push_back(i);
//		m[si].insert(m[si].end(),i);
	}
	
	for(mit=m.begin();mit!=m.end();mit++) 	
	{	
		for(vit=mit->second.begin();vit!=mit->second.end();vit++) 
		{
			cout << s[*vit] << " ";
		}
		cout << endl;
	}
}

bool comp(int T[],int P[])
{
	for(int i=0;i<256;i++)
	{
		if(T[i]!=P[i]) return false;
	}
	return true;
}

void search(char *pat, char *txt)
{
	//ABCDEEEACBDF
	// ABCDE
	int countT[256]={0};
	int countP[256]={0};
	
	int Len = strlen(pat);
	for(int i=0;i< Len;i++)
	{
		countT[txt[i]]++;
		countP[pat[i]]++;
	}
	
	for(int i=Len;i<strlen(txt);i++)
	{
		if (comp(countP, countT))
			cout << "Found at Index " << (i - Len) << endl;
		countT[txt[i]]++;
		countT[txt[i-Len]]--;
	}
	
	if (comp(countP, countT))
		cout << "Found at Index " << (strlen(txt) - Len) << endl;
}

bool bit_anagram_check(ull a, ull b)
{
    // _popcnt64(a) gives number of 1's present
    // in binary representation of a.
    return (_popcnt64(a) == _popcnt64(b));
}

// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;

/* A utility function to check whether a word
is present in dictionary or not. An array of
strings is used for dictionary. Using array
of strings for dictionary is definitely not
a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string str)
{

	int len = str.length();
	len--;
	for (int i=0; i<len; i++)
	{
		if (str[i] != str[len])
			return false;
		len--;
	}
	return true;

}

//prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str)
{
	// last argument is prefix
	wordBreakUtil(str, str.size(), "");
}

// result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
	//Process all prefixes one by one
	for (int i=1; i<=n; i++)
	{
		//extract substring from 0 to i in prefix
		string prefix = str.substr(0, i);

		// if dictionary conatins this prefix, then
		// we check for remaining string. Otherwise
		// we ignore this prefix (there is no else for
		// this if) and try next
		if (dictionaryContains(prefix))
		{
			// if no more elements are there, print it
			if (i == n)
			{
				// add this element to previous prefix
				result += prefix;
				cout << result << endl; //print result
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}	 //end for
}//end function

void generate(int ones, int zeroes, string str, int len)
{
    // If length of current string becomes same as desired length
    if (len == str.length())
    {
        cout << str << "  ";
        return;
    }
 
 //	cout<<"BEFORE GEN::ONES::"<<ones<<"::ZEROES::"<<zeroes<<"::STRIng::"<<str<<"::LEN::"<<len<<endl;
    // Append a 1 and recur
    generate(ones+1, zeroes, str+"1", len);
 
// 	cout<<"AFTER GEN::ONES::"<<ones<<"::ZEROES::"<<zeroes<<"::STRIng::"<<str<<"::LEN::"<<len<<endl;
    // If there are more 1's, append a 0 as well, and recur
    if (ones > zeroes)
    {
//    	cout<<"INSIDE IF GEN::ONES::"<<ones<<"::ZEROES::"<<zeroes<<"::STRIng::"<<str<<"::LEN::"<<len<<endl;
        generate(ones, zeroes+1, str+"0", len);
//      cout<<"BELOW IF GEN::ONES::"<<ones<<"::ZEROES::"<<zeroes<<"::STRIng::"<<str<<"::LEN::"<<len<<endl;
	}
}

void strToBinary(string s)
{
    int n = s.length();
 
 
    for (int i = 0; i <= n; i++)
    {
        // convert each char to
        // ASCII value
        int val = int(s[i]);
 
        // Convert ASCII value to binary
        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin = '1'+bin :
                       bin = '0'+bin ;
            val /= 2;
        }
//        reverse(bin.begin(), bin.end());
 
        cout << bin << " ";
    }
}

string addBinary(string a, string b)
{
	//aa="1101" bb="100"
	
	string result = "";
	int carry = 0,sum = 0;
	
	int a1 = a.length()-1,b1 = b.length()-1;
	
	while(a1 >= 0 || b1 >= 0 || sum==1 )
	{
		if(a1>=0)
		{
			sum = sum+int(a[a1]-'0');	
		}
		
		if(b1>=0)
		{
			sum = sum+int(b[b1]-'0');
		}

		result = char(sum%2+'0')+result;
		sum = sum/2;
		a1--;
		b1--;
	}
	
	return result;
}

int main()
{
	char s [] = "GeeksForGeeks";
	reverse(s);  // Reverse 

	char s1 [] = "Geeks,For!Geeks";
	ReverseSpl(s1);
	cout<< "FINAL String ::"<<s1<<endl;

	char dup [] = "geeksforgeeks";
	removeDuplicates(dup);
	
	char s2 [] = "geeksforgeeks";
	cout<< "USING HASHING " << removeDupHash(s2)<<endl;;
	
	char s3 [] = "geeksforgeeks";
	cout<<" Get max occurring char::"<<endl;
	maxOccurChar(s3);
	
	char s4 [] = "geeksforgeeks";
	cout<<" Get kth non repeating char::"<<endl;
	int k = 1;
	kthNonRepeat(s4,k);
	
	char s5 [] = "abcdaa";
	cout<<"Count substring with equal ends ::";
	cout<<countSubs(s5);
	cout<<endl;
	
	string str = "aaaabbaaccccccccde";
    cout<<"MAX REPEATING ::"<< maxRepeating(str)<<endl;
    
    int n = 3;
    cout<<"Number of String with given constraints::"<<numStringLen(n)<<endl;
    
    string words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle"};
    int n1 = sizeof(words)/sizeof(words[0]);
    wordsWithSameCharSet(words, n1);

	string str2 = "xyyx";
	cout << countOfAnagramSubstring(str2) << endl;

	char str3 [] = "21234";
    cout << "evenNumSubstrin::"<<evenNumSubstring(str3) << endl;	    

	string str4 = "abbcccc";   // Input 1
    int k2 = 2;
    cout << minStringValue(str4, k2) << endl;
    
    char str5[] = "geeksforgeeks";
    char mask_str[]  = "mask";
    printf("%s", removeDirtyChars(str5, mask_str));
    cout<<endl;
    
    string s6[20]= {"geeksquiz", "geeksforgeeks", "abcd", 
                    "forgeeksgeeks", "zuiqkeegs"};
	print_anagrams(s6,5);

	char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    
    ull a = 8, b = 4;
    cout << bit_anagram_check(a, b) << endl;
    
    cout << "First Test:\n";
	wordBreak("geeks");

	cout << "\nSecond Test:\n";
	wordBreak("abccba");
	
	string str8 = "";
	generate(0, 0, str8, 4);
	cout<<endl;
	
	string s9 = "geeks";
    strToBinary(s9);
	cout<<endl;
	
	string aa = "1101", bb="100";
    cout << addBinary(aa, bb) << endl;
    
	return 1;
}
