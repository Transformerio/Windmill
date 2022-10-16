#include <iostream>
#include <string>
#include <array>

#include <time.h>

#define new_2Darr(X, Y) std::array<std::array<std::auto, Y>, X>
void delay(int secs){
	// Converting time into milli_seconds
	int milli_seconds = 1000 * secs;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds);
}
void ClearScreen(){
	std::cout << std::string( 100, '\n' );
}

template<std::size_t r_SIZE, std::size_t c_SIZE>
void gridMe(std::array<std::array<std::string, c_SIZE>, r_SIZE>a1,
	std::array<std::array<std::string, c_SIZE>, r_SIZE>a2,
	std::array<std::array<std::string, c_SIZE>, r_SIZE>a3,
	std::array<std::array<std::string, c_SIZE>, r_SIZE>a4){
	int grNum = (2*r_SIZE)+1;
	int gcNum = (2*c_SIZE)+1;
	std::array<std::array<std::string, c_SIZE*2>, r_SIZE*2>master;
	for(int r = 0; r<r_SIZE;r++){
		for(int c=0; c<c_SIZE;c++){
			master[r][c] = a1[r][c];
			master[r][c+c_SIZE] = a2[r][c];
			master[r+r_SIZE][c] = a3[r][c];
			master[r+r_SIZE][c+c_SIZE] = a4[r][c];
		}
	}
	for(int r =0; r<r_SIZE*2;r++){
		for(int c = 0; c<c_SIZE*2;c++){
			std::cout<<master[r][c]<<" ";
		}
		std::cout<<std::endl;
	}
}

template<std::size_t r_SIZE, std::size_t c_SIZE>
void windMill(std::array<std::array<std::string, c_SIZE>, r_SIZE>arr){
	if(r_SIZE % 2 != 0 && c_SIZE % 2 != 0)
		std::cout << "array is not compatible for reason: NON-EVEN" << std::endl;
	std::array<std::array<std::string, c_SIZE>, r_SIZE>temp;
	for(int r=0; r<r_SIZE; r++){
		for(int c=0; c<c_SIZE;c++){
			temp[r][c] = arr[r][c];
		}
	}

	std::array<std::array<std::string, r_SIZE/2>, c_SIZE/2> TL;
	std::array<std::array<std::string, r_SIZE/2>, c_SIZE/2> TR;
	std::array<std::array<std::string, r_SIZE/2>, c_SIZE/2> BR;
	std::array<std::array<std::string, r_SIZE/2>, c_SIZE/2> BL;
	
  //top left
	for(int r=0; r<r_SIZE/2; r++){
		for(int c = 0; c < c_SIZE/2; c++){
			TL[r][c] = temp[r][c];
		}
	}

  //top right
	for(int r=0; r < r_SIZE/2; r++){
		for(int c = 0; c < c_SIZE/2; c++){
			TR[r][c] = temp[r][c+c_SIZE/2];
		}
	}

  //bottom left
	for(int r = 0; r < r_SIZE/2; r++){
		for(int c = 0; c < c_SIZE/2; c++){
			BL[r][c] = temp[r+r_SIZE/2][c];
		}
	}

	// bottom right
	for(int r = 0; r < r_SIZE/2; r++){
		for(int c = 0; c < c_SIZE/2; c++){
			BR[r][c] = temp[r+r_SIZE/2][c+c_SIZE/2];
		}
	}
/*
	//TESTING PRINT
	for(int r =0; r<3;r++){
		for(int c = 0; c<3;c++){
			std::cout<<BR[r][c]<<" ";
		}
		std::cout<<std::endl;
	}
*/
	ClearScreen();
	while (true){
		for(int i = 0; i<4; i++){
			std::cout<< "            V Spinning Flag V             " << std::endl;
			std::cout<<std::endl;
			if(i==0)
				gridMe(TL, TR, BL, BR);
			else if(i==1)
				gridMe(BR, TL, TR, BL);
			else if(i==2)
				gridMe(BL, BR, TL, TR);
			else
				gridMe(TR, BL, BR, TL);
			std::cout<<std::endl;
			std::cout << "     https://github.com/Transformerio     " << std::endl;
			delay(200);
			ClearScreen();
		}	
	}
	//std::array<std::array<std::array<std::string, 3>, 3>, 4> = { TL, TR, BL, BR };
	//gridMe(TL, TR, BL, BR);
}

int main() {
	std::array<std::array<std::string, 18>, 18>windowArr = {{
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"1", "1", "1", "1", "1", "1","1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
		{"0", "0", "0", "0", "0", "0","0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"}
	}};
	windMill(windowArr);
} 
