bool isPrime(int num)
{
    int primef = 2;
    if(num==1) return false;
    while(num>=primef*primef)
    {
        if(num%primef==0) return false;
        else primef++;
    }
    return true;
}