#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void elf_check(unsigned char *e_ident);
void _print_magic(unsigned char *e_ident);
void _print_class(unsigned char *e_ident);
void  _print_data(unsigned char *e_ident);
void _print_version(unsigned char *e_ident);
void _print_osabi(unsigned char *e_ident);
void _print_abi(unsigned char *e_ident);
void _print_type(unsigned int e_type, unsigned char *e_ident);
void _print_entry(unsigned long int e_entry, unsigned char *e_ident);
void elf_close(int elf);
int main(int __attribute__((__unused__)) argc, char *argv[]);
/**
 * elf_check - checks if a file is an ELF.
 * @e_ident: pointer to an arrayof bytes specifies
 * how to interpret the file
 *
 * Description: if a file is not an ELF - exit with code 98.
 */
void elf_check(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: file is not an ELF\n");
			exit(98);
		}
	}
}
/**
 * _print_magic - prints the magic numbers of a file (ELF)
 * @e_ident: points to an array
 *
 * Description: magic numbers are seperated by spaces
 */
void _print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * _print_class - prints or identifies the architecture or clase
 * of the ELF header.
 * @e_ident: points to array
 *
 */
void _print_class(unsigned char *e_ident)
{
	printf("  class:                ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n"); /* This class is invalid. */
		break;
	case ELFCLASS32:
		printf("ELF32\n"); /* This defines the 32-bit architecture.*/
		break;
	case ELFCLASS64:
		printf("ELF64\n"); /* This defines the 64-bit architecture.*/
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * _print_data - prints data of ELF header.
 * @e_ident: pointer to an array
 *
 */
void  _print_data(unsigned char *e_ident)
{
	printf("  Data:                ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE: /* Unknown data format.*/
		printf("none\n");
		break;
	case ELFDATA2LSB: /*Two's complement, little-endian.*/
		printf("2's complement, little-endian\n");
		break;
	case ELFDATA2MSB: /* Two's complement, big-endian.*/
		printf("2's complement, big-endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}
/**
 * _print_version - prints the version of the ELF header file
 * @e_ident: pointer to an array
 *
 */
void _print_version(unsigned char *e_ident)
{
	printf("  Version:               %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT: /*Current version.*/
		printf("  (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * _print_osabi - prints OS/ABI of an ELF header
 * @e_ident: pointer to an array
 */
void _print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                     ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE: /* Same as ELFOSABI_SYSV*/
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX: /*HP-UX ABI*/
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Stand-alone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * _print_abi - prints ABI version of an ELF header
 * @e_ident: pointer to an array
 *
 */
void _print_abi(unsigned char *e_ident)
{
	printf("  ABI VERSION:                %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * _print_type - prints type of an ELF header
 * @e_type: ELF type
 * @e_ident: pointer to an array
 */
void _print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                           ");

	switch (e_type)
	{
	case ET_NONE: /*An unknown type.*/
		printf("NONE (None)\n");
		break;
	case ET_REL: /* A relocatable file.*/
		printf("REL (Relocatble file)\n");
		break;
	case ET_EXEC: /*An executable file.*/
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN: /*A shared object.*/
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE: /*A core file.*/
		printf("CORE (Core file)\n");
		break;
	default:
		printf("unknown: %x>\n", e_type);
	}
}
/**
 * _print_entry - prints entry points of elf header
 * @e_entry: address of elf entry pont
 * @e_ident: ponter to an array containing ELF class.
 */
void _print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * elf_close - closes an elf file
 * @ELF: file descriptor
 *
 * Descriptor: if file can not be close - exit code 98.
 */
void elf_close(int ELF)
{
	if (close(ELF) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close ELF %d\n", ELF);
		exit(98);
	}
}
/**
 * main - displays information contained in elf header
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: 0 on success
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int hop, hrd;

	hop = open(argv[1], O_RDONLY);
	if (hop == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(hop);
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	hrd = read(hop, header, sizeof(Elf64_Ehdr));
	if (hrd == -1)
	{
		free(header);
		elf_close(hop);
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}
	elf_check(header->e_ident);
	printf("ELF Header:\n");
	_print_magic(header->e_ident);
	_print_class(header->e_ident);
	_print_data(header->e_ident);
	_print_version(header->e_ident);
	_print_osabi(header->e_ident);
	_print_abi(header->e_ident);
	_print_type(header->e_type, header->e_ident);
	_print_entry(header->e_entry, header->e_ident);

	free(header);
	elf_close(hop);

	return (0);
}
