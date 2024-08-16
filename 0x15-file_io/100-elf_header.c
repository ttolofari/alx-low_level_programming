#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <elf.h>
#include "main.h"

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit with code 98.
 */
void check_elf(unsigned char *e_ident)
{
    if (e_ident[0] != ELFMAG0 || e_ident[1] != ELFMAG1 ||
        e_ident[2] != ELFMAG2 || e_ident[3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}

/**
 * print_header_info - Prints the information contained in the ELF header.
 * @e_ident: A pointer to an array containing the ELF identification.
 * @e_type: The type of the ELF file.
 * @e_entry: The entry point address of the ELF file.
 *
 * Description: Prints all the required fields of the ELF header.
 */
void print_header_info(unsigned char *e_ident, uint16_t e_type, uint64_t e_entry)
{
    /* Print magic numbers */
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");

    /* Print class */
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        break;
    }

    /* Print data encoding */
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
        break;
    }

    /* Print version and OS/ABI */
    printf("  Version:                           %d", e_ident[EI_VERSION]);
    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");

    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
        break;
    }

    /* Print ABI version */
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

    /* Print type */
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type = (e_type >> 8) | (e_type << 8);

    printf("  Type:                              ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
        break;
    }

    /* Print entry point address */
    printf("  Entry point address:               ");
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed, exit with code 98.
 */
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF file or if an error occurs,
 *              exit with code 98.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        close_elf(fd);
        exit(98);
    }

    check_elf(header.e_ident);

    printf("ELF Header:\n");
    print_header_info(header.e_ident, header.e_type, header.e_entry);

    close_elf(fd);
    return (0);
}

