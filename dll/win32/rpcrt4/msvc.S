
#include <asm.inc>

#ifdef _M_IX86
.code32

EXTERN _ndr_client_call:PROC

PUBLIC _call_stubless_func
_call_stubless_func:

    mov ecx, [esp+4]                /* This Pointer */
    mov ecx, [ecx]                  /* This->lpVtbl */
    mov ecx, [ecx-8]                /* MIDL_STUBLESS_PROXY_INFO */
    mov edx, [ecx+8]                /* Info->FormatStringOffset */
    movzx edx, word ptr [edx+eax*2] /* FormatStringOffset[index] */
    add edx, [ecx+4]                /* info->ProcFormatString + offset */
    movzx eax, byte ptr [edx+1]     /* Oi_flags */
    and eax, 8                      /* Oi_HAS_RPCFLAGS */
    shr eax, 1
    movzx eax, word ptr [edx+eax+4] /* arguments size */
    push eax
    lea eax, [esp+8]                /* &This */
    push eax
    push edx                        /* format string */
    push [ecx]                      /* info->pstubdesc */
    call _ndr_client_call
    lea esp, [esp+12]
    pop edx                         /* arguments size */
    mov ecx, [esp]                  /* return address */
    add esp, edx
    jmp ecx
#else
.code64

EXTERN ndr_client_call:PROC

PUBLIC call_stubless_func
FUNC call_stubless_func
    mov [rsp + 8], rcx
    .SAVEREG rcx, 8
    mov [rsp + 10h], rdx
    .SAVEREG rdx, 10h
    mov [rsp + 18h], r8
    .SAVEREG r8, 18h
    mov [rsp + 20h], r9
    .SAVEREG r9, 20h
    sub rsp, 38h
    .ALLOCSTACK 38h
    .ENDPROLOG

    lea r8, [rsp +38h + 8]   /* &This */
    mov rcx, [rcx]           /* This->lpVtbl */
    mov rcx, [rcx - 10h]     /* MIDL_STUBLESS_PROXY_INFO */
    mov rdx, [rcx + 10h]     /* info->FormatStringOffset */
    movzx rdx, word ptr [rdx+r10*2] /* FormatStringOffset[index] */
    add rdx, [rcx + 8]       /* info->ProcFormatString + offset */
    mov rcx, [rcx]           /* info->pStubDesc */

    movaps [rsp + 20h], xmm1
    movaps [rsp + 28h], xmm2
    movaps [rsp + 30h], xmm3
    lea r9, [rsp + 18h]      /* fpu_args */
    call ndr_client_call
    add rsp, 38h
    ret
ENDFUNC

PUBLIC call_server_func
FUNC call_server_func
    push rbp
    .PUSHREG rbp
    mov rbp, rsp
    push rsi
    .PUSHREG rsi
    push rdi
    .PUSHREG rdi
    .ENDPROLOG

    mov rax, rcx   /* function to call */
    mov rcx, 32    /* allocate max(32,stack_size) bytes of stack space */
    cmp r8, rcx
    cmovg rcx, r8
    sub rsp, rcx
    and rsp, NOT 15
    mov rcx, r8
    shr rcx, 3
    mov rdi, rsp
    mov rsi, rdx
    rep movsq       /* copy arguments */
    mov rcx, [rsp]
    mov rdx, [rsp + 8]
    mov r8, [rsp + 16]
    mov r9, [rsp + 24]
    movd xmm0, rcx
    movd xmm1, rdx
    movd xmm2, r8
    movd xmm3, r9
    call rax

    lea rsp, [rbp - 16] /* restore stack */
    pop rdi
    pop rsi
    pop rbp
    ret
ENDFUNC


PUBLIC NdrClientCall2
FUNC NdrClientCall2
    mov [rsp + 18h], r8
    .SAVEREG r8, 18h
    mov [rsp + 20h], r9
    .SAVEREG r9, 20h
    sub rsp, 28h
    .ALLOCSTACK 28h
    .ENDPROLOG

    lea r8, [rsp + 28h + 18h]
    xor r9, r9
    call ndr_client_call

    add rsp, 28h
    ret
ENDFUNC

EXTERN ndr_async_client_call:PROC
PUBLIC NdrAsyncClientCall
FUNC NdrAsyncClientCall
    mov [rsp + 18h], r8
    .SAVEREG r8, 18h
    mov [rsp + 20h], r9
    .SAVEREG r9, 20h
    sub rsp, 28h
    .ALLOCSTACK 28h
    .ENDPROLOG

    lea r8, [rsp + 28h + 18h]
    call ndr_async_client_call

    add rsp, 28h
    ret
ENDFUNC

#endif

END
