//����1 ʹ�ñ��������
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() == t.size()) {
			sort(s.begin(), s.end());
			sort(t.begin(), t.end());
			//for (int i=0;i<s.size();++i) {
			//    if(s[i]!=t[i])
			//        return false;
			//}
			//return true;
			return s == t; 
		}
		return false;
	}
};

//����2������hash
/*class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size()==t.size()) {
			unordered_map<char,int> sTab,tTab;
			for (int i=0;i<s.size();++i) {
				sTab[s[i]]++;
				tTab[t[i]]++;
			}
			if (sTab.size()==tTab.size()) {
				for (auto it = sTab.begin();it!=sTab.end();it++) {
					if (tTab.find(it->first)==tTab.end() || tTab[it->first]!=it->second)
						return false;
				}
				return true;
			}
			return false;
		}
		return false;
	}
};*/

//һ��hash
/*
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size()==t.size()) {
			unordered_map<char,int> sTab;
			for (int i=0;i<s.size();++i) {
				sTab[s[i]]++;
				sTab[t[i]]--;
			}
			for (auto it = sTab.begin();it!=sTab.end();it++) {
				if (it->second != 0)
					return false;
			}
			return true;
		}
		return false;
	}
};
*/
//�����hash
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		int map[26] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			map[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			map[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (map[i] > 0) {
				return false;
			}
		}
		return true;
	}
};
/******************************************/