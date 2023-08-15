#include <bits/stdc++.h>
using namespace std;

bool cmpForSort(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

bool cmpForEraseAlphaNum(char c)
{
    return !isalnum(c);
}
int main()
{
    
    map<string, int> freqOfWords;

    for (int i = 1; i <= 10; ++i)
    {
        // creating fileName => file1.txt
        string filename = "file" + to_string(i) + ".txt";

        ifstream file(filename);
        // now we  hav eacces of full file , but if we try to print that in one tim ewe cant do that
        string word;
        // file  will give word one by one and store that in word variable
        while (file >> word)
        {
            // word is equal to any word like => Example's
            transform(word.begin(), word.end(), word.begin(), ::tolower); // now Example' => example's

            word.erase(remove_if(word.begin(), word.end(), cmpForEraseAlphaNum), word.end()); // now example' => examples

            if (!word.empty()) // if the word was &$@-% after  processing it became empty string the the  frequency should be not count
            {

                freqOfWords[word]++;
            }
        }
        // file content complete close that
        file.close();
    }
    // initialize new array with frequency
    vector<pair<string, int>> sortedWords(freqOfWords.begin(), freqOfWords.end());
    // sort the array so highest frequency will be on top, that can be also don ewith heap but im using compare function
    sort(sortedWords.begin(), sortedWords.end(), cmpForSort);

    cout << "Frequency of Top " << 10 << " Words From All Files" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << sortedWords[i].first << " => "
             << " occur " << sortedWords[i].second << " times" << endl;
    }
    cout << endl;

    for (int i = 1; i <= 10; ++i)
    {
        // now doing all previous oprations for every file and pring 10  words for each
        cout << "Frequency of Top " << 10 << " Words in file" << i << ".txt:" << endl;
        map<string, int> filefreqOfWords;
        string filename = "file" + to_string(i) + ".txt";
        ifstream file(filename);

        string word;
        while (file >> word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word.erase(remove_if(word.begin(), word.end(), cmpForEraseAlphaNum),
                       word.end());

            if (!word.empty())
            {
                filefreqOfWords[word]++;
            }
        }

        file.close();

        vector<pair<string, int>> sortedFileWords(filefreqOfWords.begin(), filefreqOfWords.end());
        sort(sortedFileWords.begin(), sortedFileWords.end(), cmpForSort);
        // printing 10 words from ithe file
        // i can add one more condition , if the words are very less the or maybe the size of freq array is less the 10 then this code will break
        for (int j = 0; j < 10; j++)
        {
            cout << sortedFileWords[j].first << " => "
                 << " occur " << sortedFileWords[j].second << " times" << endl;
        }

        cout << endl;
    }

    return 0;
}
