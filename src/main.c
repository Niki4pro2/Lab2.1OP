#include <stdio.h>

#include "bitset/bitset.h"
#include "handlers/errors.h"
#include "output/output.h"

void example_op() {
    size_t UniversumSize = 10;

    BitSet A = bitsetCreate(UniversumSize);
    int elementsA[5] = {2, 3, 4, 5, 6};
    bitsetAddMany(&A, elementsA, 5);

    BitSet B = bitsetCreate(UniversumSize);
    int elementsB[4] = {1, 2, 4, 9};
    bitsetAddMany(&B, elementsB, 4);

    BitSet C = bitsetCreate(UniversumSize);
    int elementsC[4] = {4, 5, 7, 8};
    bitsetAddMany(&C, elementsC, 4);

    BitSet D = bitsetCreate(UniversumSize);
    int elementsD[5] = {3, 4, 6, 7, 8};
    bitsetAddMany(&D, elementsD, 5);

    // Операции по заданному выражению
    BitSet _1 = getSetsSymmetricDifference(&B, &C);   // B Δ C
    BitSet _2 = getSetsDifference(&A, &_1);           // A - (B Δ C)
    BitSet _3 = getComplementSet(&D);                 // ¬D
    BitSet _4 = getSetsIntersection(&_3, &B);         // (¬D ∩ B)
    BitSet _5 = getSetsDifference(&_4, &A);           // ((¬D ∩ B) - A)
    BitSet _6 = getSetsUnion(&_2, &_5);               // A - (B Δ C) ∪ ((¬D ∩ B) - A)
    BitSet _7 = getSetsIntersection(&C, &D);          // (C ∩ D)
    BitSet Result = getSetsUnion(&_6, &_7);           // A - (B Δ C) ∪ ((¬D ∩ B) - A) ∪ (C ∩ D)

    printSet("Result", Result.bits, Result.capacity);
}

int main() {
    example_op();
    return 0;
}

