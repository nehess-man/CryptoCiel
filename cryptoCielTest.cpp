// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
    // Partie Hash (SHA-256)
    HashGestion LM;
    std::string File = "test.txt";
	std::cout << LM.CalculateFileSHA256(File) << std::endl;

    // Partie AES
    AesGestion aes;
    aes.GenerateAESKey();
    aes.SaveAESKeyToFile("aes_random.key");
    aes.EncryptFileAES256("test.txt", "testencrypt.txt");
    aes.DecryptFileAES256("testencrypt.txt", "testdecrypt.txt");

    // Partie RSA
    RsaGestion rsa;

    // Génération de la paire de clés RSA
    std::string publicKeyFile = "rsaVL_public.pem";
    std::string privateKeyFile = "rsaVL_private.pem";
    rsa.generationClef(publicKeyFile, privateKeyFile, 2048);

    // Message à chiffrer
    std::string message = "Salut man";
    std::cout << "Message original: " << message << std::endl;

    // Chiffrement avec RSA
    std::string encryptedMessage = rsa.chiffrementRsa(message);
    std::cout << "Message chiffré (base64): " << encryptedMessage << std::endl;

    // Déchiffrement avec RSA
    std::string decryptedMessage = rsa.dechiffrementRsa(encryptedMessage);
    std::cout << "Message déchiffré: " << decryptedMessage << std::endl;

    return 0;
}
