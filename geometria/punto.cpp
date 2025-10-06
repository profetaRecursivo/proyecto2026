#define tipo long long
struct pto
{
    tipo x, y;
    pto(tipo _x = 0, tipo _y = 0): x(_x), y(_y){}
    const pto operator + (const pto& otro) const {
        return pto(x + otro.x, y + otro.y);
    }    
    const pto operator - (const pto& otro) const {
        return pto(x  - otro.x, y - otro.y);
    }
    const pto operator*(const pto& otro) const {
        return pto(x*otro.x, y*otro.y);
    }
    const tipo operator%(const pto& otro) const {
        return x*otro.y - y*otro.x;
    }
    const bool operator ==(const pto& otro) const{
        return x == otro.x and y == otro.y;
    }
    const pto operator*(const tipo k)const{
        return pto(x*k, y*k);
    } 
};