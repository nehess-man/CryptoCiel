// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
	HashGestion LM;
	std::string File = "test.txt";
	std::cout << LM.CalculateFileSHA256(File) << std::endl;

	AesGestion ana;
	ana.GenerateAESKey();
	ana.SaveAESKeyToFile("aes_random.key");
	ana.EncryptFileAES256("test.txt", "testencrypt.txt");
	ana.DecryptFileAES256("testencrypt.txt", "testdecrypt.txt");


	return 0;

}


