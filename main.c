/*
 * main.c
 *
 *  Created on: Apr 6, 2018
 *      Author: mishors
 */


int main()
{
	int val = Hash_init(1000);
	Hash_insert(12);
	Hash_insert(112);
	Hash_insert(212);

	printf("12 found  = %d\n",Hash_lookup(12));
	printf("112 found = %d\n",Hash_lookup(112));
	printf("112 found = %d\n",Hash_lookup(2102));
}
