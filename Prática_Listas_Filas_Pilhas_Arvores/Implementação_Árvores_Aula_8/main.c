#include <stdio.h>
#include <stdlib.h>

typedef long TipoChave;
typedef struct No *Apontador;
typedef Apontador TipoDicionario;

typedef struct Registro {
    TipoChave Chave;
} Registro;

typedef struct No {
    Registro Reg;
    Apontador pEsq, pDir;
} No;

int calculoFB ( No *pRaiz ){
    if ( pRaiz == NULL )
        return 0;
    return Altura( pRaiz -> pEsq ) - Altura ( pRaiz -> pDir);
}

int Altura ( No *pRaiz ){
    int iEsq, iDir;
    if ( pRaiz == NULL )
        return 0;
    iEsq = Altura ( pRaiz -> pEsq );
    iDir = Altura ( pRaiz -> pDir );
    if ( iEsq > iDir )
        return iEsq + 1;
    else 
        return iDir + 1;
}
void RSE ( No **ppRaiz ){
    No *pAux;
    pAux = ( *ppRaiz ) -> pDir;
    ( *ppRaiz ) -> pDir = pAux -> pEsq;
    pAux -> pEsq = ( *ppRaiz );
    (*ppRaiz) = pAux;
}
void RSD ( No **ppRaiz ){
    No *pAux;
    pAux = ( *ppRaiz ) -> pEsq;
    ( *ppRaiz ) -> pEsq = pAux -> pDir;
    pAux -> pDir = ( *ppRaiz );
    (*ppRaiz) = pAux;
}
int BalancaEsquerda ( No ** ppRaiz ){
    int fbe = FB ( ( *ppRaiz) -> pEsq );
    if ( fbe > 0 ){
        RSD ( ppRaiz );
        return 1;
    }
    else if ( fbe < 0) // Rotação Dupla Direita
    {
        RSE (&((*ppRaiz)->pEsq) );
        RSD ( ppRaiz );
        return 1;
    }
    return 0;
}
int BalancaEsquerda ( No ** ppRaiz ){
    int fbd = FB ( ( *ppRaiz) -> pDir );
    if ( fbd > 0 ){
        RSE ( ppRaiz );
        return 1;
    }
    else if ( fbd < 0) // Rotação Dupla Direita
    {
        RSD (&((*ppRaiz)->pDir) );
        RSE ( ppRaiz );
        return 1;
    }
    return 0;
}
int Balanceamento ( No **ppRaiz ){
    int fb = FB( *ppRaiz );
    if ( fb > 1 )
        return BalancaEsquerda ( ppRaiz );
    else if ( fb < -1 )
        return BalancaDireita ( ppRaiz );
    else    
        return 0;
}
int insercao( No **ppRaiz, Registro *x ){
    if ( *ppRaiz == NULL ){
        *ppRaiz = ( No * ) malloc ( sizeof ( No ) );
        ( *ppRaiz ) -> Reg = *x;
        ( *ppRaiz ) -> pEsq = NULL;
        ( *ppRaiz ) -> pDir = NULL;
        return 1;
    } else if ( ( *ppRaiz) -> Reg.Chave > x -> Chave) {
        if ( insercao ( &( *ppRaiz ) -> pEsq, x ) ){
            if ( Balanceamento ( ppRaiz ))
                return 0;
            else 
                return 1;
        }
    }
    else if ( (*ppRaiz) -> Reg.Chave < x -> Chave){
        if ( insercao ( &( *ppRaiz ) -> pDir, x ) ){
            if ( Balanceamento ( ppRaiz ))
                return 0;
            else 
                return 1;
        }
        else 
            return 0;
    }
    else
        return 0;
}