
int main() {

// konstante Zeiger
char s[20];        // s ist konstanter Zeiger
char* const t = s; // t ist konstanter Zeiger
s++; t++;          // geht beides nicht

// konstanter Inhalt
const char* u = "Halli";
u[3]=s[3];         // geht nicht
u = s;             // geht!

// konstanter Zeiger auf konstanten Inhalt
const char* const v = "Hallo";
v[3]=s[3];         // geht nicht
v = s;             // geht auch nicht mehr

return 0;
}
