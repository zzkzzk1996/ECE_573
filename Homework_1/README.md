# README
## ECE-573-Homework-1
### Name: **Zekun Zhang
### NetId: **zz364
### Email: \<zekunzhang.1996@gmail.com\>

For every code script of corresponding question, I used code to read all the data from the dataset: (just like the code I displayed below)
```cpp
	string preFileName = "../hw1-1.data/";
    string postFileName = "int.txt";
    vector<int> fileList = {8, 32, 128, 512, 1024, 4096, 4192, 8192};
	string file = to_string(fileList[i]) + postFileName;
    string fileName = preFileName + file;
```
As the code I displayed in my code file, I just change the name of ‘fileName’ to achieve automatic inputs. **If you want to test with other datasets, you can just change the fileName and comment all of the other codes I displayed*.
Notes: all this snippets are in the ‘_FileReader.cpp_’.