#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdarg.h>

/**
 * print_error_and_exit - Prints an error message and exits the program.
 * @exit_code: The exit code for the program.
 * @format: The format string for the error message.
 * @...: The additional arguments for the format string.
 */
void print_error_and_exit(int exit_code, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    exit(exit_code);
}

/**
 * print_elf_header_info - Prints the ELF header information.
 * @ehdr: Pointer to the ELF header.
 */
void print_elf_header_info(const Elf64_Ehdr *ehdr)
{
    printf("Magic:   %02x %02x %02x %02x\n",
           ehdr->e_ident[EI_MAG0], ehdr->e_ident[EI_MAG1],
           ehdr->e_ident[EI_MAG2], ehdr->e_ident[EI_MAG3]);

    printf("Class:                             ");
    switch (ehdr->e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Data:                              ");
    switch (ehdr->e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Version:                           %d (current)\n", ehdr->e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (ehdr->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Tru64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("Unknown (%d)\n", ehdr->e_ident[EI_OSABI]);
            break;
    }

    printf("ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (ehdr->e_type)
    {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Unknown (%d)\n", ehdr->e_type);
            break;
    }

    printf("Entry point address:               0x%lx\n", (unsigned long)ehdr->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * Return: 0 on success, or 98 on failure.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr ehdr;

    if (argc != 2)
    {
        print_error_and_exit(97, "Usage: %s elf_filename\n", argv[0]);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error_and_exit(98, "Error: Can't open file %s\n", argv[1]);
    }

    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
    {
        close(fd);
        print_error_and_exit(98, "Error: Can't read ELF header from file %s\n", argv[1]);
    }

    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr.e_ident[EI_MAG3] != ELFMAG3)
    {
        close(fd);
        print_error_and_exit(98, "Error: Not an ELF file - %s\n", argv[1]);
    }

    print_elf_header_info(&ehdr);

    if (close(fd) == -1)
    {
        print_error_and_exit(100, "Error: Can't close fd %d\n", fd);
    }

    return (0);
}

