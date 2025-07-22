#pragma once

#include "clsScreen.h"
#include "clsInput.h"
#include <string>
#include <vector>
using std::string; 
using std::vector; 

class clsUtil
{
public: 
    // string
    static vector<string> SplitString(string S1, string Delim)
    {
        vector<string> vString;

        short pos = 0;
        string sWord; 

        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);    
            
            if (sWord != "")
                vString.push_back(sWord);
            

            S1.erase(0, pos + Delim.length());
        }

        if (S1 != "")
        {
            vString.push_back(S1); 
        }

        return vString;
    }

    static vector <string> AddLineBreaks(string S, short LineLength)
    {
        vector <string> vTokens = SplitString(S, " ");
        
        vector <string> BrokenS; 
        string BrokenSToken = "";

        short CharCounter = 0; 

        for (int i = 0; i < vTokens.size(); i++)
        {
            BrokenSToken += vTokens[i] + " ";
            CharCounter += vTokens[i].length() + 1;

            if (CharCounter >= LineLength)
            {
                BrokenSToken.pop_back(); // removes tailing space
                BrokenS.push_back(BrokenSToken);
                BrokenSToken.clear();
                CharCounter = 0; 
            }

            if (i == vTokens.size() - 1 && (!BrokenSToken.empty()))
            {
                BrokenS.push_back(BrokenSToken);
                break;
            }
        }

        return BrokenS;
    }

    static bool ConfirmOperation(string Message)
    {
        cout << clsScreen::Setw(35) << Message << " y/n -->";
        char Confirm = clsInput::ReadChar();

        return (tolower(Confirm) == 'y') ? true : false;
    }

};
