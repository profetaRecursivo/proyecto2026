bool dentro(point_i &p, point_i &a, point_i &b) {
    return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x) and
           min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
}//aparte verificar colinearidad