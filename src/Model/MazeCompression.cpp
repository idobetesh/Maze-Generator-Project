#include "MazeCompression.h"

MazeComperssion::MazeComperssion(Maze2d m) : maze(m){};

string MazeComperssion::compress(vector<char> &data) const
{
    string intigerValues = "";
    int startContent = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == 'A' || data[i] == 'B' || data[i] == 'C' || data[i] == 'D')
        {
            startContent = i;
            break;
        }
        intigerValues += data[i];
    }

    string compressData = "";
    char prevChar = data[startContent];
    int count = 1;

    for (int i = startContent + 1; i < data.size(); i++)
    {
        if (data[i] == prevChar)
        {
            count++;
        }
        else
        {
            compressData += prevChar + to_string(count);
            prevChar = data[i];
            count = 1;
        }
    }

    compressData += prevChar + to_string(count);
    intigerValues += compressData;

    return intigerValues;
}

vector<char> MazeComperssion::decompress(string data)
{
    vector<char> decompressedData;
    int startContent = 0;

    vector<char> letter;
    vector<int> times;

    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == 'A' || data[i] == 'B' || data[i] == 'C' || data[i] == 'D')
        {
            startContent = i;
            letter.push_back(data[i]);
            break;
        }
        decompressedData.push_back(data[i]);
    }

    int sizeOfNum = 0;
    for (int i = startContent + 1; i < data.length(); i++)
    {
        while (i < data.length())
        {
            if (data[i] == 'A' || data[i] == 'B' || data[i] == 'C' || data[i] == 'D')
            {
                letter.push_back(data[i]);
                break;
            }
            sizeOfNum = sizeOfNum * 10 + data[i] - '0';
            i++;
        }

        times.push_back(sizeOfNum);
        sizeOfNum = 0;
    }

    for (int i = 0; i < letter.size(); i++)
    {
        for (int j = 0; j < times[i]; j++)
        {
            decompressedData.push_back(letter[i]);
        }
    }
    return decompressedData;
}

void MazeComperssion::save(ofstream &out_file) const
{
    vector<char> charVec;

    vector<char> temp = maze.getData();
    string tmp = compress(temp);

    for (int i = 0; i < tmp.length(); i++)
        charVec.push_back(tmp[i]);

    int len = charVec.size();

    out_file.write((char *)&len, sizeof(int));

    char *longString = new char[len + 1];

    for (int i = 0; i < len; i++)
        longString[i] = charVec[i];

    longString[len] = '\0';

    out_file.write(longString, len);
}

Maze2d& MazeComperssion::load(ifstream &in_file)
{
    int len;
    in_file.read((char *)&len, sizeof(int));
    char *longString = new char[len + 1];
    in_file.read(longString, len);
    longString[len + 1] = '\0';

    string dataStr = longString;

    vector<char> data = decompress(dataStr);

    for (int i = 0; longString[i] != '\0'; i++)
        data.push_back(longString[i]);

    Maze2d tmpMaze(data);
    maze = tmpMaze;
    return maze;
    // cout << "LODED: \n"
    //      << maze;
}
