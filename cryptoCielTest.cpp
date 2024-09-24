#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
    // Partie Hash (SHA-256)
    HashGestion LM;
    std::string File = "test.txt";
    LM.CalculateFileSHA256(File);  // Calcul du hash SHA-256

    // Partie AES
    AesGestion aes;
    aes.GenerateAESKey();
    aes.SaveAESKeyToFile("aes_random.key");
    aes.EncryptFileAES256("test.txt", "testencrypt.txt");
    aes.DecryptFileAES256("testencrypt.txt", "testdecrypt.txt");

    // Partie RSA
    RsaGestion rsa;
    rsa.chargementClefs("rsaVL_public.pem", "rsaVL_private.pem");
    std::string message = "Salut man";
    rsa.chiffreDansFichier(message, "message_chiffre_rsa.txt");
    std::string decryptedMessage = rsa.dechiffreFichier("message_chiffre_rsa.txt");
    rsa.chiffrementFichier("test.txt", "testencrypt_rsa.txt", true);
    rsa.dechiffrementFichier("testencrypt_rsa.txt", "testdecrypt_rsa.txt", true);

    return 0;
}
