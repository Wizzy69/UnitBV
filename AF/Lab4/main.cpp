int cautareBinara(int *&vector, int element, int stanga, int dreapta)
{
    int mijloc = (stanga + dreapta) / 2;
    if (stanga > dreapta)
        return -1;
    if (vector[mijloc] == element)
        return mijloc;
    if (vector[mijloc] > element)
        return cautareBinara(vector, element, stanga, mijloc - 1);
    return cautareBinara(vector, element, mijloc + 1, dreapta);
}