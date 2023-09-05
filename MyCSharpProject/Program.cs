using System;


public struct s21_decimal
{
    public uint[] bits;

    public s21_decimal(uint[] bits)
    {
        this.bits = bits;
    }
}


public class Program
{
    public static uint multiply(ref decimal value)
    {
        uint multiplications = 0;
        while (value % 1 != 0)
        {
            value *= 10;
            multiplications++;
        }
        return multiplications;
    }
    public static void multiplyMul(ref decimal value, uint times)
    {
        for (int i = 0; i < times; i++)
        {
            value *= 10;
        }
    }
    public static decimal decimalPow(decimal baseNumber, uint exponent)
    {
        decimal result = 1m;
        for (int i = 0; i < exponent; i++)
        {
            result *= baseNumber;
        }
        return result;
    }
    public static void dprint(s21_decimal val)
{
    Console.WriteLine($"{val.bits[0]}, {val.bits[1]}, {val.bits[2]}, {val.bits[3]}");
}
    public static s21_decimal s21add(s21_decimal val1, s21_decimal val2)
    {
        uint scale1 = (val1.bits[3] << 1) >> 17;
        uint scale2 = (val2.bits[3] << 1) >> 17;
        decimal dec1 = (decimal)val1.bits[0] + (decimal)val1.bits[1] * 4294967296m + (decimal)val1.bits[2] * 18446744073709551616m;
        if((val1.bits[3] >> 31) == 1) dec1 *= -1;
        decimal dec2 = (decimal)val2.bits[0] + (decimal)val2.bits[1] * 4294967296m + (decimal)val2.bits[2] * 18446744073709551616m;
        if((val2.bits[3] >> 31) == 1) dec2 *= -1;
        decimal sum = (dec1 / decimalPow(10, scale1)) + (dec2 / decimalPow(10, scale2));
        uint scale3 = (multiply(ref sum)) << 16;
        decimal num1 = Math.Abs(sum) / 18446744073709551616m;
        decimal temp1 = Math.Abs(sum) - decimal.Truncate(num1) * 18446744073709551616m;
        decimal num2 = temp1 / 4294967296m;
        decimal num3 = temp1 - decimal.Truncate(num2) * 4294967296m;
        uint n1 = (uint)decimal.Truncate(num1);
        uint n2 = (uint)decimal.Truncate(num2);
        uint n3 = (uint)decimal.Truncate(num3);
        s21_decimal result = new s21_decimal(new uint[] { n3, n2, n1, scale3 });
        if(sum < 0) result.bits[3] |= 0x80000000;

        return result;
    }
    public static s21_decimal s21sub(s21_decimal val1, s21_decimal val2)
    {
        uint scale1 = (val1.bits[3] << 1) >> 17;
        uint scale2 = (val2.bits[3] << 1) >> 17;
        decimal dec1 = (decimal)val1.bits[0] + (decimal)val1.bits[1] * 4294967296m + (decimal)val1.bits[2] * 18446744073709551616m;
        if((val1.bits[3] >> 31) == 1) dec1 *= -1;
        decimal dec2 = (decimal)val2.bits[0] + (decimal)val2.bits[1] * 4294967296m + (decimal)val2.bits[2] * 18446744073709551616m;
        if((val2.bits[3] >> 31) == 1) dec2 *= -1;
        decimal sum = (dec1 / decimalPow(10, scale1)) - (dec2 / decimalPow(10, scale2));
        uint scale3 = (multiply(ref sum)) << 16;
        decimal num1 = Math.Abs(sum) / 18446744073709551616m;
        decimal temp1 = Math.Abs(sum) - decimal.Truncate(num1) * 18446744073709551616m;
        decimal num2 = temp1 / 4294967296m;
        decimal num3 = temp1 - decimal.Truncate(num2) * 4294967296m;
        uint n1 = (uint)decimal.Truncate(num1);
        uint n2 = (uint)decimal.Truncate(num2);
        uint n3 = (uint)decimal.Truncate(num3);
        s21_decimal result = new s21_decimal(new uint[] { n3, n2, n1, scale3 });
        if(sum < 0) result.bits[3] |= 0x80000000;

        return result;
    }

    // Console.WriteLine("Целая часть числа: " + multiply(ref sum));
        public static s21_decimal s21mul(s21_decimal val1, s21_decimal val2)
    {
        uint scale1 = (val1.bits[3] << 1) >> 17;
        uint scale2 = (val2.bits[3] << 1) >> 17;
        decimal dec1 = (decimal)val1.bits[0] + (decimal)val1.bits[1] * 4294967296m + (decimal)val1.bits[2] * 18446744073709551616m;
        if((val1.bits[3] >> 31) == 1) dec1 *= -1;
        decimal dec2 = (decimal)val2.bits[0] + (decimal)val2.bits[1] * 4294967296m + (decimal)val2.bits[2] * 18446744073709551616m;
        if((val2.bits[3] >> 31) == 1) dec2 *= -1;
        decimal sum = (dec1 / decimalPow(10, scale1)) * (dec2 / decimalPow(10, scale2));
        Console.WriteLine("Целая часть числа: " + sum);
        uint scale3 = (uint)(BitConverter.GetBytes(decimal.GetBits(sum)[3])[2]) << 16;
        multiplyMul(ref sum, (scale3 >> 16));
        decimal num1 = Math.Abs(sum) / 18446744073709551616m;
        decimal temp1 = Math.Abs(sum) - decimal.Truncate(num1) * 18446744073709551616m;
        decimal num2 = temp1 / 4294967296m;
        decimal num3 = temp1 - decimal.Truncate(num2) * 4294967296m;
        uint n1 = (uint)decimal.Truncate(num1);
        uint n2 = (uint)decimal.Truncate(num2);
        uint n3 = (uint)decimal.Truncate(num3);
        s21_decimal result = new s21_decimal(new uint[] { n3, n2, n1, scale3 });
        if(sum < 0) result.bits[3] |= 0x80000000;

        return result;
    }

    public static void Main()
    {
        uint e1 = 65536;
        uint m1 = 0x80000000;
        s21_decimal decimalValue1 = new s21_decimal(new uint[] {212331, 32333, 2513221, e1*6});
        s21_decimal decimalValue2 = new s21_decimal(new uint[] {145312, 0, 0, e1*2});
        s21_decimal res = s21mul(decimalValue1, decimalValue2);
        dprint(res);
        m1--;
    }
}
