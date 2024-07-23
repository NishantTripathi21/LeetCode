class Solution {
public:
    void solutionRE(string &s, string &part){
        int found=s.find(part);
        if(found!=string::npos){
            //substring located,remove it
            s.erase(found,part.size());
        }
        else return;

        solutionRE(s,part);
    }
    string removeOccurrences(string s, string part) {
        //solutionRE( s, part);
        method2Iteration(s,part);
        return s;
        
    }
    //method 2 by iteration
    void method2Iteration(string &s,string part){
        int pos=s.find(part);
        while(pos!=string::npos){
            s.erase(pos,part.length());
            pos=s.find(part);
        }
    }
};
