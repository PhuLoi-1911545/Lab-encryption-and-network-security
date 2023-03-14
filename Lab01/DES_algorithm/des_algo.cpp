#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;


// Table to generate key
int PC_1[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
};

int PC_2[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
};

int Left_shift[16] = {
	1, 1, 2, 2, 2, 2, 2, 2,
	1, 2, 2, 2, 2, 2, 2, 1
};

int initial_permutation[64] = {
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
};

vector<int> final_permutation = {
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
};

int Extend_table[48]{
	32,1,2,3,4,5,
	4,5,6,7,8,9,
	8,9,10,11,12,13,
	12,13,14,15,16,17,
	16,17,18,19,20,21,
	20,21,22,23,24,25,
	24,25,26,27,28,29,
	28,29,30,31,32,1
};

vector<vector<int>> S_box1{
	{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
	{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
	{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
	{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

vector<vector<int>> S_box2{
	{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
	{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
	{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
	{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
};

vector<vector<int>> S_box3{
	{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
	{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
	{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
	{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
};

vector<vector<int>> S_box4{
	{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
	{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
	{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
	{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
};

vector<vector<int>> S_box5{
	{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
	{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
	{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
	{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
};

vector<vector<int>> S_box6{
	{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
	{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
	{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
	{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
};

vector<vector<int>> S_box7{
	{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
	{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
	{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
	{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
};

vector<vector<int>> S_box8{
	{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
	{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
	{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
	{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11},
};

vector<vector<vector<int>>> S_box_list{
	S_box1, S_box2, S_box3, S_box4, S_box5, S_box6, S_box7, S_box8
};

vector<int> functionF_P = {
	16,7,20,21,
	29,12,28,17,
	1,15,23,26,
	5,18,31,10,
	2,8,24,14,
	32,27,3,9,
	19,13,30,6,
	22,11,4,25
};

// Convert a hex character to 4 bit string
string hex_char_to_bin_string(char hex_char) {
	int value;
	if (hex_char < 'A') {
		value = hex_char - '0';
	}
	else {
		value = hex_char - 'A' + 10;
	}
	return bitset<4>(value).to_string();
}

// binary string length must be a number dividable by 4
string binary_string_to_hex_string(string binary) {
	string result;
	int length = binary.length();
	int loop = length / 4;
	for (int i = 0; i < loop; i++) {
		string temp = binary.substr(i * 4, 4);
		int val = bitset<4>(temp).to_ulong();
		if (val < 10) {
			result += '0' + val;
		}
		else {
			result += 'A' + (val - 10);
		}
	}
	return result;
}

// Receive a 6-bit binary, through a Sbox, produce a 4-bit binary
string Sbox_pass(string sixbit_string, vector<vector<int>>Sbox) {
	string Sbox_result;
	string rowValue = "";
	rowValue += sixbit_string[0];
	rowValue += sixbit_string[5];
	int row = bitset<2>(rowValue).to_ulong();
	int column = bitset<4>(sixbit_string.substr(1, 4)).to_ulong();
	Sbox_result = bitset<4>(Sbox[row][column]).to_string();
	//printf("%d - %d ; %s\n", row, column, Sbox_result.c_str());
	return Sbox_result;
}

// Xor 2 binary string 
string Xor_function(string left_bin, string right_bin) {
	string xorResult;
	// in this case, the string only contain '1' or '0', so the value can only 1 or 0
	int string_length = left_bin.length();
	for (int i = 0; i < string_length; i++) {
		int val1 = left_bin[i] - '0';
		int val2 = right_bin[i] - '0';
		int myxor = val1 ^ val2;
		xorResult += bitset<1>(myxor).to_string();
	}
	return xorResult;
}


string functionF(string R_n_1, string K_n) {
	// First, expand R[n-1] from 32 bits to 48 bits using Extend array
	string extendR;
	for (int i = 0; i < 48; i++) {
		extendR += R_n_1[Extend_table[i] - 1];
	}
	printf("Extended R = %s\n", extendR.c_str());
	// Xor extendR with Key_n
	string xorResult = Xor_function(extendR, K_n);
	printf("Xor result : %s\n", xorResult.c_str());
	// use 8 S-box to shrink 48bits to 32 bits. each Sbox receive a 6-bits string
	// and return 4-bits string
	string SboxResult;
	for (int i = 0; i < 8; i++) {
		string sixbit_string = xorResult.substr(0 + i * 6, 6);
		//printf("%s\n", sixbit_string.c_str());
		SboxResult += Sbox_pass(sixbit_string, S_box_list[i]);
	}
	printf("Sbox result : %s\n", SboxResult.c_str());
	// perform a permutation on the SboxResult.
	string finalFResult;
	for (int i = 0; i < 32; i++) {
		finalFResult += SboxResult[functionF_P[i] - 1];
	}
	printf("F function result : %s\n", finalFResult.c_str());
	return finalFResult;
}

void DES_encryption(string message, string key, int loop) {
	if (loop > 16) {
		printf("loop value must be <= 16!");
		return;
	}
	// Step 1. Create 16 subkeys, each of which is 48-bits long
	string messageb, keyb;
	for (int i = 0; i < 16; i++) {
		messageb += hex_char_to_bin_string(message[i]);
		keyb += hex_char_to_bin_string(key[i]);
	}
	printf("message in binary %s\n", messageb.c_str());
	printf("key in binary %s\n", keyb.c_str());
	// create K+ using PC_1
	string k_plus;
	for (int i = 0; i < 56; i++) {
		k_plus += keyb[PC_1[i] - 1];
	}
	printf("K+ in binary %s\n", k_plus.c_str());
	vector<string>Cx, Dx;
	Cx.push_back(k_plus.substr(0, 28));
	Dx.push_back(k_plus.substr(28));
	printf("\nList of all Cx and Dx generated from Key...\nC0 = %s\nD0 = %s\n\n", Cx.front().c_str(), Dx.front().c_str());
	for (int i = 1; i <= 16; i++) {
		string preC = Cx.back();
		string preD = Dx.back();
		string newC = preC.substr(Left_shift[i - 1]) + preC.substr(0, Left_shift[i - 1]);
		string newD = preD.substr(Left_shift[i - 1]) + preD.substr(0, Left_shift[i - 1]);
		Cx.push_back(newC);
		Dx.push_back(newD);
		printf("C%d = %s\nD%d = %s\n\n", i, Cx.at(i).c_str(), i, Dx.at(i).c_str());

	}
	// Create Kx (56 bit of each CxDx to 48 bit) using PC-2
	vector<string>Kx;
	Kx.push_back("K0 does not exist");
	printf("\nList of all keys....\n");
	for (int i = 1; i <= 16; i++) {
		string newKey, groupCD;
		groupCD = Cx.at(i) + Dx.at(i);
		for (int j = 0; j < 48; j++) {
			//PC_2 count from 1, not 0. So to 
			//access the first element of string, we must decrease by 1
			newKey += groupCD[PC_2[j] - 1];
		}
		Kx.push_back(newKey);
		printf("K%d = %s\n", i, Kx.at(i).c_str());
	}
	// Yay, we got all the keys!
	// Step 2: Encode each 64-bit block of data
	// Initial permutation.
	string IP;
	for (int i = 0; i < 64; i++) {
		IP += messageb[initial_permutation[i] - 1];
	}
	printf("\nInitial permutation is %s\n", IP.c_str());
	printf("\nStart running %d rounds....\n\n", loop);
	vector<string> Leftx, Rightx;
	Leftx.push_back(IP.substr(0, 32)); // L[0]
	Rightx.push_back(IP.substr(32));	// R[0]
	/*
	L[n] = R[n-1]
	R[n] = L[n-1] + f(R[n-1],K[n])
	*/
	for (int i = 1; i <= loop; i++) {
		printf("==============Round%d===============\n", i);
		string newRightN = Xor_function(Leftx.back(), functionF(Rightx.back(), Kx.at(i)));
		Leftx.push_back(Rightx.back());
		Rightx.push_back(newRightN);
		printf("L%d = %s\nR%d = %s\n\n", i, Leftx.at(i).c_str(), i, Rightx.at(i).c_str());
	}

	string reverseFinal;
	reverseFinal += Rightx.back();
	reverseFinal += Leftx.back();
	
	printf("reverseFinal : %s\n", reverseFinal.c_str());
	string final;
	for (int i = 0; i < 64; i++) {
		final += reverseFinal[final_permutation[i] - 1];
	}
	printf("Encoded message using DES: \n%s\n", final.c_str());
	printf("In hex: \n%s\n\n", binary_string_to_hex_string(final).c_str());
}

int main() {
	string message = "0123456789ABCDEF";
	string key = "0123456789AB2750";
	DES_encryption(message, key, 1);
	return 0;
}