#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

 void hashMD5(char * in, char * out){

	int len_in;
	int len_out;
	int i;
	//char hash[16];
	//char dump[33];
	char hash[20];
	char dump[41];
	DWORD ret;
	HCRYPTPROV hCryptProv;
	HCRYPTHASH hHash;
 DWORD dwHashLen;
	DWORD dwCount;
	char asciihash[512];
	int p = 0;
	
	dwHashLen = sizeof(DWORD);

	len_out= sizeof(hash);
	len_in = 0;
	while (in[len_in] != '\0'){
		len_in++;
	}

	printf("data = (%s).\n",in);

	if(!CryptAcquireContext(&hCryptProv,NULL,NULL,PROV_RSA_FULL,0)){
		ret = GetLastError();
		printf("Acquisition of context failed (%x).\n",ret);
	}


	if(!CryptCreateHash(hCryptProv,CALG_SHA1,0,0,&hHash)){
		ret = GetLastError();
		printf("Error during CryptBeginHash (%x).\n",ret);
	}

	if(!CryptHashData(hHash,&in[0],len_in,0)){
		ret = GetLastError();
		printf("Error during CryptHashData (%x).\n",ret);
	}

 if(!CryptGetHashParam(hHash, HP_HASHSIZE, (BYTE *)&dwHashLen, &dwCount, 0)){
  printf("Error during CryptGetHashParam.\n");
 }

	if(!CryptGetHashParam(hHash, HP_HASHVAL, &hash[0], &dwHashLen, 0)){
		printf("Error during CryptGetHashParam.\n");
	}

	p=0;
	for (i = 0; i < 20; i++)
	{
		convertHexaToString(&hash[i],&asciihash[p]);
		p += 2;
	}
	asciihash[40] = '\0';
	memcpy(out, &asciihash[0],40);
	

	for (i = 0;i < 40;i++){
		dump[i] = out[i]; 
	}
	dump[40] = '\0';

	printf("hash = (%s).\n",dump);
	
	if(hHash) 
	 CryptDestroyHash(hHash);
	if(hCryptProv) 
	 CryptReleaseContext(hCryptProv,0);

}