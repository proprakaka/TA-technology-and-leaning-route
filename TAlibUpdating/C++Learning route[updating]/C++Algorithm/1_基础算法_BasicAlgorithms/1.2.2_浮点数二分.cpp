int bsearch_f(double l, double r)
{
    while (r - l > 1e-6) //这里如果题目要求保留n位小数，那么则精度为1e(-n-2),避免误差
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}