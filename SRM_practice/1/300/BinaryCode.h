#pragma once
#include <string>
#include <vector>

using namespace std;

class BinaryCode
{
	string decode(string encryptedMessage, char startDigit)
	{
		vector<char> originalMessage(1,startDigit);
		string result;

		for (unsigned int i=1; i<encryptedMessage.length(); i++)
		{
			originalMessage.push_back(encryptedMessage[i-1] - '0' - originalMessage[i-1]);
			if (i >= 2)
				originalMessage[i] -= originalMessage[i-2];
			
			if (originalMessage[i] < 0 || originalMessage[i] > 1)
				return "NONE";
		}

		if ( encryptedMessage[encryptedMessage.length() -1] - '0' != originalMessage[originalMessage.size()-1] + originalMessage[originalMessage.size()-2] )
			return "NONE";
		
		for (unsigned int i=0; i<encryptedMessage.length(); i++)
			result.push_back('0' + originalMessage[i]);
		
		return result;
	}
public:
	vector<string> decode(string rawData)
	{
		vector<string> result;
		
		result.push_back(decode(rawData, 0));
		result.push_back(decode(rawData, 1));
		
		return result;
	}
};
