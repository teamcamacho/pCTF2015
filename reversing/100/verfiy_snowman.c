struct s0 {
    int32_t* f0;
    int32_t* f8;
};

/* .calloc */
void* calloc(int64_t rdi, int64_t rsi);

int64_t verify(struct s0* rdi, int32_t esi) {
    struct s0* v3;
    int32_t v4;
    int32_t eax5;
    int64_t rax6;
    int32_t edx7;
    int32_t eax8;
    void* rax9;
    void* v10;
    int32_t v11;
    int32_t eax12;
    int32_t v13;
    int32_t v14;
    int32_t eax15;
    int64_t rax16;
    int32_t edx17;
    int32_t eax18;
    int32_t* rax19;
    int32_t v20;
    int32_t v21;
    int32_t eax22;
    int64_t rax23;
    int32_t edx24;
    int32_t eax25;
    int32_t eax26;
    int64_t rax27;
    int32_t edx28;
    int32_t eax29;
    int32_t v30;
    int32_t v31;
    int32_t v32;
    int32_t eax33;
    int32_t v34;
    int32_t v35;
    int64_t rax36;
    int32_t v37;
    int32_t v38;
    int32_t v39;
    int32_t v40;
    int32_t eax41;
    int32_t v42;
    int32_t v43;
    int32_t eax44;
    int64_t rax45;
    int32_t v46;
    int32_t v47;
    int32_t v48;
    int32_t v49;
    int32_t v50;
    int32_t eax51;
    int32_t v52;
    int32_t v53;
    int32_t v54;
    int32_t eax55;

    v3 = rdi;
    v4 = esi;
    eax5 = v4 * v4;
    *(int32_t*)&rax6 = eax5 + eax5;
    *((int32_t*)&rax6 + 1) = 0;
    edx7 = v4;
    eax8 = edx7;
    rax9 = calloc((int64_t)(-(eax8 + eax8 + edx7) + (int32_t)rax6 + 1), 4);
    v10 = rax9;
    v11 = 0;
    while (eax12 = v4, eax12 + eax12 - 1 > v11) {
        v13 = 0;
        while (v11 + v4 > v13) {
            v14 = *(int32_t*)((int64_t)*(int32_t**)(((int64_t)v11 << 3) + (int64_t)v3) + ((int64_t)v13 << 2));
            eax15 = v4 * v4;
            *(int32_t*)&rax16 = eax15 + eax15;
            *((int32_t*)&rax16 + 1) = 0;
            edx17 = v4;
            eax18 = edx17;
            if (-(eax18 + eax18 + edx17) + (int32_t)rax16 + 1 < v14) 
                goto addr_0x40088b_6;
            if (v14 < 0) 
                goto addr_0x40089b_8;
            if (v14 > 0) {
                rax19 = (int32_t*)((v14 - 1 << 2) + (int64_t)v10);
                *rax19 = *rax19 + 1;
            }
            ++v13;
        }
        ++v11;
    }
    v20 = 0;
    v21 = 0;
    while (eax22 = v4 * v4, *(int32_t*)&rax23 = eax22 + eax22, *((int32_t*)&rax23 + 1) = 0, edx24 = v4, eax25 = edx24, -(eax25 + eax25 + edx24) + (int32_t)rax23 + 1 > v21) {
        v20 = v20 + *(int32_t*)(((int64_t)v21 << 2) + (int64_t)v10);
        if (*(int32_t*)(((int64_t)v21 << 2) + (int64_t)v10) > 1) 
            goto addr_0x400929_16;
        ++v21;
    }
    eax26 = v4 * v4;
    *(int32_t*)&rax27 = eax26 + eax26;
    *((int32_t*)&rax27 + 1) = 0;
    edx28 = v4;
    eax29 = edx28;
    if (-(eax29 + eax29 + edx28) + (int32_t)rax27 + 1 == v20) {
        v30 = 0;
        v31 = 0;
        while (v31 < v4) {
            v30 = v30 + *(int32_t*)((int64_t)v3->f0 + ((int64_t)v31 << 2));
            ++v31;
        }
        v32 = 0;
        while (eax33 = v4, eax33 + eax33 - 1 > v32) {
            v34 = 0;
            v35 = 0;
            while (v32 + v4 > v35) {
                v34 = v34 + *(int32_t*)((int64_t)*(int32_t**)(((int64_t)v32 << 3) + (int64_t)v3) + ((int64_t)v35 << 2));
                ++v35;
            }
            if (v34 != v30) 
                goto addr_0x400a32_28;
            ++v32;
        }
    } else {
        *(int32_t*)&rax36 = 0;
        *((int32_t*)&rax36 + 1) = 0;
        goto addr_0x400cb1_31;
    }
    v37 = 0;
    while (v37 < v4) {
        v38 = 0;
        v39 = 0;
        while (v37 + v4 > v39) {
            v38 = v38 + *(int32_t*)((int64_t)*(int32_t**)(((int64_t)v39 << 3) + (int64_t)v3) + ((int64_t)v37 << 2));
            ++v39;
        }
        if (v38 != v30) 
            goto addr_0x400aaa_38;
        ++v37;
    }
    v40 = v4;
    while (eax41 = v4, eax41 + eax41 - 1 > v40) {
        v42 = 0;
        v43 = v40 - v4 + 1;
        eax44 = v4;
        *(int32_t*)&rax45 = eax44 + eax44;
        *((int32_t*)&rax45 + 1) = 0;
        v46 = ~(v40 - v4) + (int32_t)(rax45 + -1);
        v47 = 0;
        while (v47 < v46) {
            v42 = v42 + *(int32_t*)((int64_t)*(int32_t**)(((int64_t)(v43 + v47) << 3) + (int64_t)v3) + ((int64_t)v40 << 2));
            ++v47;
        }
        if (v42 != v30) 
            goto addr_0x400b55_46;
        ++v40;
    }
    v48 = 0;
    while (v48 < v4) {
        v49 = 0;
        v50 = 0;
        while (eax51 = v4, eax51 + eax51 - 1 - v48 > v50) {
            v49 = v49 + *(int32_t*)((int64_t)*(int32_t**)(((int64_t)(v50 + v48) << 3) + (int64_t)v3) + ((int64_t)v50 << 2));
            ++v50;
        }
        if (v49 != v30) 
            goto addr_0x400bd9_54;
        ++v48;
    }
    v52 = 1;
    while (v52 < v4) {
        v53 = 0;
        v54 = 0;
        while (eax55 = v4, eax55 + eax55 - 1 - v52 > v54) {
            v53 = v53 + *(int32_t*)((int64_t)*(int32_t**)(((int64_t)v54 << 3) + (int64_t)v3) + ((int64_t)(v54 + v52) << 2));
            ++v54;
        }
        if (v53 != v30) 
            goto addr_0x400c54_62;
        ++v52;
    }
    if (*v3->f8 + *v3->f0 == 20) {
        if (*v3->f0 == 9) {
            *(int32_t*)&rax36 = 1;
            *((int32_t*)&rax36 + 1) = 0;
        } else {
            *(int32_t*)&rax36 = 0;
            *((int32_t*)&rax36 + 1) = 0;
        }
    } else {
        *(int32_t*)&rax36 = 0;
        *((int32_t*)&rax36 + 1) = 0;
    }
    addr_0x400cb1_31:
    return rax36;
    addr_0x400c54_62:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x400bd9_54:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x400b55_46:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x400aaa_38:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x400a32_28:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x400929_16:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x40088b_6:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
    addr_0x40089b_8:
    *(int32_t*)&rax36 = 0;
    *((int32_t*)&rax36 + 1) = 0;
    goto addr_0x400cb1_31;
}