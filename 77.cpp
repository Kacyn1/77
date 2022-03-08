#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "string"

using namespace std;

class cos_tam {
public:
ifstream fIn1;
ifstream fIn2;
ofstream fOut;
int xd = 0;
cos_tam();
~cos_tam();
string code(string key, string txt);
string decode(string key, string txt);
void count(string txt);};

		cos_tam::cos_tam() {
    				
					fIn1.open("c:\\dokad.txt");
					
					
    fIn2.open("c:\\szyfr.txt");
    	fOut.open("c:\\Vigenere_wyniki.txt");
}

				cos_tam::~cos_tam() {
    			fIn1.close();
    			fIn2.close();
    			fOut.close();
}

		string cos_tam::code(string key, string txt) {
string lol = "";
	    int whiteChars = 0;
    			for (int i = 0; i < txt.length(); i++) {
        		if (txt[i] == ' ') {
            			lol += ' ';
            		whiteChars++;
}
				        else if (txt[i] == '.') {
            		lol += '.';
            whiteChars++;
}
else if (txt[i] == ',') {
            lol += ',';


            whiteChars++;}
        		else {
int x = i - whiteChars;
int k = int(txt[i] - 'A') + int(key[x % key.length()] - 'A');
lol += char((k % 26) + 'A');
        }
    }

			xd = ceil(float(txt.length() - whiteChars) / key.length());
return lol;
}

string cos_tam::decode(string key, string txt) {
string lol = "";
    int whiteChars = 0;
    for (int i = 0; i < txt.length(); i++) {
        if (txt[i] == ' ') {
            lol += ' ';
            whiteChars++;
        }
        else if (txt[i] == '.') {
            lol += '.';
            whiteChars++;
        }
        else if (txt[i] == ',') {
            lol += ',';
            whiteChars++;
        }
        else {
            int x = i - whiteChars;
            int k = int(txt[i] - 'A') - int(key[x % key.length()] - 'A');
            while(k < 0) {
                k += 26;
            }
            
            lol += char(k + 'A');
        }
    }

    
    return lol;
}

				void cos_tam::count(string txt) {
    		int t[26];
    			for (int i = 0; i < 26; i++) {
        t[i] = 0;
    }
    for (int i = 0; i < txt.length(); i++) {
        t[txt[i] - 'A' ]++;
    }
    				for (int i = 0; i < 26; i++) {
fOut<<char(i+'A')<<":"<<t[i]<<endl;
}

   		 double k = 0;
    			for (int i = 0; i < 26; i++) {
    				
    				
    				
int l = 0;
l += (t[i] - 1) * t[i];
k += l;
}
int sum = 0;
for (int i = 0; i < 26; i++) {
sum += t[i];
}int n = (sum - 1) * sum;
k = k / n;
    
double d;


    double ko = k;
    
    
    ko = ko - 0.0385;
    d = 0.0285 / ko;
    
    d += 0.005;
    d = 0.01 * int(100 * d);
    fOut << "wyniki" << endl;
    fOut << d<<endl;
    fOut << round(d);
   
    
}

int main()
{
    cos_tam t1;
    string f1;
    					getline(t1.fIn1, f1);
    	t1.fOut << "77.1" << endl;
    		t1.fOut << t1.code("LUBIMYCZYTAC", f1) << endl;
    	t1.fOut << "liczba powtorzen: " << t1.xd << endl;
    			string f2, c2;
    		t1.fOut << "77.2" << endl;
    
getline(t1.fIn2, f2);
    			getline(t1.fIn2, c2);
    t1.fOut << c1.decode(c2, f2)<<endl;
    t1.fOut << "77.3" << endl;
    t1.count(f2);

}
