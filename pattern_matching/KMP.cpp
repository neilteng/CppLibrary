// time complexity ave and worst case:O(n+m); space complexity: O(m)

#include<iostream>
#include<vector>
#include<string>

void ComputePrefixTable(const std::string & pattern,std::vector<int> &prefixT){
    // prefixT.size()= pattern.size()+1, which 1 is based to avoid extra checks.
    // the whole prefix table right shift by 1 position.
    for(int prefixPt=0,surfixPT=1;surfixPT<pattern.size();){
            if(pattern[prefixPt]==pattern[surfixPT]){
                prefixT[++surfixPT]=++prefixPt;
                }
            else{
                if (prefixPt==0){prefixT[++surfixPT]=0;}
                else{prefixPt=prefixT[prefixPt];}
            }
    }
}

int KMPSearch(const std::string & target, const std::string & pattern) {
    if (pattern.size()==0 || target.size()==0){return -1;}
    std::vector<int> prefTable(pattern.size() + 1); // 1-based to avoid extra checks.
    ComputePrefixTable(pattern,prefTable);
    int cnt=0;
    for (int i=0,j=0;i<target.size();){
        std::cout<<"i: "<<i<<"; j: "<<j<<'\n';
        if(target[i]==pattern[j]){
            i++;j++;
                if(j==pattern.size()){
                    cnt++;
                    std::cout<<cnt<<". match's index in target is "<<i-pattern.size()<<'\n';
                    j = prefTable[j];//after match we need to consider next match!!
                    }
            }
        else{
            if (j==0){i++;}
            else {j=prefTable[j];}
        }
    }
    if (cnt==0){return -1;}
    else{return cnt;}
}

// Driver program to test above function 
int main() 
{ 
    std::string txt = "ABABDABACDABABCABAB"; 
    std::string pat = "ABABCABAB"; 
    KMPSearch(txt, pat); 
    return 0; 
} 