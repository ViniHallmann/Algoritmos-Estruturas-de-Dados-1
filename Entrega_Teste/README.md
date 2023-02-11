# Algoritmos-Estruturas-de-Dados-1
## Vinícius Hallmann - M1

Convenção usada: https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf <br/>
Link para o exercio no LeetCode (206. Reverse Linked List): https://leetcode.com/problems/reverse-linked-list/ <br/>

### Observação: O arquivo resultados_erros_padroes.txt são os erros que o Dr. Memory detecta no Windows, independente do programa no qual ele está ánalisando, então estes erros podem aparecer no resultado final deste programa.

O que funciona: O código nao funciona!<br/>
O que não funciona: Codigo inverte mas a repeticao nao para e possui vazamento de 16 bytes .<br/>

### Teste 1:<br/>
Entrada: 1 2 3 4 5<br/>
Saída: 5 2 3 4 1    <br/>

### Teste 2:<br/>
Entrada: 1 2 <br/>
Saída:   2 1    <br/>

### Teste 3: <br/>
Entrada: ""<br/>
Saída: "Lista Vazia"    <br/>

Link da análise no google drive: https://drive.google.com/file/d/1-FYHw8C6tPhF8H31Z1w3Gmchpu75PMRj/view?usp=sharing <br/>

### Análise Dr. Memory: <br/>

Dr. Memory version 2.5.0 build 0 built on Oct 18 2021 03:01:22
Windows version: WinVer=105;Rel=2009;Build=19044;Edition=CoreSingleLanguage
Dr. Memory results for pid 12808: "entrega_teste.exe"
Application cmdline: ""D:\Arquivos\Programação\Prática Algoritmos e Estruturas de Dados 1\entrega_teste.exe""
Recorded 124 suppression(s) from default C:\Program Files (x86)\Dr. Memory\bin64\suppress-default.txt

Error #1: UNADDRESSABLE ACCESS beyond top of stack: reading 0x00000085ad3ff490-0x00000085ad3ff498 8 byte(s)
0 ___chkstk_ms                            [../../../../../src/gcc-git-10.3.0/libgcc/config/i386/cygwin.S:132]
1 _pei386_runtime_relocator               [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/pseudo-reloc.c:477]
2 __tmainCRTStartup                       [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:279]
3 .l_start                                [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:212]
4 KERNEL32.dll!BaseThreadInitThunk
Note: @0:00:00.147 in thread 12396
Note: 0x00000085ad3ff490 refers to 744 byte(s) beyond the top of the stack 0x00000085ad3ff778
Note: instruction: or     $0x0000000000000000 (%rcx) -> (%rcx)

Error #2: UNADDRESSABLE ACCESS: reading 0x0000000000000000-0x0000000000000004 4 byte(s)
0 inverteLista               [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:434]
1 main                       [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:434]
Note: @0:00:00.190 in thread 12396
Note: instruction: mov    (%rax) -> %edx

Error #3: UNINITIALIZED READ: reading 0x00000085ad3fe0ea-0x00000085ad3fe0f0 6 byte(s) within 0x00000085ad3fe0e0-0x00000085ad3fe108
0 ntdll.dll!RcContinueExit
1 ntdll.dll!RtlUnwindEx
2 ntdll.dll!RtlUserThreadStart
Note: @0:00:03.030 in thread 12396
Note: instruction: iret   %rsp (%rsp) -> %rsp

Error #4: LEAK 16 direct bytes 0x0000021b62b80360-0x0000021b62b80370 + 0 indirect bytes
0 replace_malloc               [d:\a\drmemory\drmemory\common\alloc_replace.c:2580]
1 cria_lista                   [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:434]
2 main                         [C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crtexe.c:434]

===========================================================================
FINAL SUMMARY:

DUPLICATE ERROR COUNTS:
	Error #   1:      2
	Error #   3:      3

SUPPRESSIONS USED:

ERRORS FOUND:
      2 unique,     3 total unaddressable access(es)
      1 unique,     3 total uninitialized access(es)
      0 unique,     0 total invalid heap argument(s)
      0 unique,     0 total GDI usage error(s)
      0 unique,     0 total handle leak(s)
      0 unique,     0 total warning(s)
      1 unique,     1 total,     16 byte(s) of leak(s)
      0 unique,     0 total,      0 byte(s) of possible leak(s)
ERRORS IGNORED:
      1 potential error(s) (suspected false positives)
         (details: C:\Users\vinic\AppData\Roaming\Dr. Memory\DrMemory-entrega_teste.exe.12808.000\potential_errors.txt)
      6 unique,     6 total,   1515 byte(s) of still-reachable allocation(s)
         (re-run with "-show_reachable" for details)
Details: C:\Users\vinic\AppData\Roaming\Dr. Memory\DrMemory-entrega_teste.exe.12808.000\results.txt