class K {
public:
 int x;
};

K k; K *pK=&k;
// Zugriff auf Komponente x im Zeigerziel:
(*pK).x;  /* oder kuerzer: */ pK->x;

