#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>

using namespace std;

int main(){
	string text = "";
	int height = 0;
	int width = 0;
	string line;
	
	//reading the file
	ifstream myfile ("input.txt");
	if (myfile.is_open()){
		while ( getline (myfile,line) ){
		  text = text + line;
		  height++;
		}
	myfile.close();
	}
	width = line.length();
	int arr[height][width];
	
	//converting input text to integer
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; j++){
			arr[i][j] = (text[(i*width)+j]) - 48;
		}
	}
	
	//count neighbours
	while(true){
		int newArr[height][width];
		system("cls");
		for(int i = 0; i < height; ++i){
			for(int j = 0; j < width; j++){
				newArr[i][j] = arr[i][j];
				int neighbours = 0;
				int north = i%height-1;
				int west = j%width-1;
				int south = i%height+1;
				int east = j%width+1;
				if(arr[north][west]==1){
					neighbours++; //northwest
				}
				if(arr[north][j]==1){
					neighbours++; //north
				}
				if(arr[north][east]==1){
					neighbours++; //northeast
				}
				if(arr[i][east]==1){
					neighbours++; //east
				}
				if(arr[south][east]==1){
					neighbours++; //southeast
				}
				if(arr[south][j]==1){
					neighbours++; //south
				}
				if(arr[south][west]==1){
					neighbours++; //southwest
				}
				if(arr[i][west]==1){
					neighbours++; //west
				}
				if(neighbours<2 || neighbours>3){ //underpopulated or overpopulated
					newArr[i][j]=0;
				}
				if(neighbours==3){ //reproduction
					newArr[i][j]=1;
				}
			}
		}
		for(int i = 0; i < height; ++i){
			for(int j = 0; j < width; j++){
				if(newArr[i][j] == 0){
					cout<<" ";
				}
				else{
					cout<<"#";
				}
				arr[i][j] = newArr[i][j]; //assigning the new generation
			}
			cout<<endl;
		}
		Sleep(1);
	}
	return 0;
}
