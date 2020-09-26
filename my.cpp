#include "my.h"

Field::Field()
{
    head = nullptr;
    cur = nullptr;
    k = 0;
}

Field::~Field()
{
    while(head)
    {
        cur = head;
        head = head->pNext;
        delete cur;
    }
    delete head;

}

Circle::Circle()
{
    x = 0;
    y = 0;
    r = 0;
}


Circle* Field::operator[] (const int index)
{
	printf("1\n");
	if (index < k)
	{
		cur = this->head;

		while (cur != nullptr)
		{
			if (cur->k == index) return cur;
			cur = cur->pNext;
		}
	}
	return cur;
}
int Field::read(const char* filename)
{
    FILE* fin = fopen(filename, "r");

    int n = 0, k = 0;
    double x, y, r;

    if(fin == nullptr)
    {
        printf("No File\n");
        return -1;
    }

    while(k == 0)
      {
        if((fscanf(fin, "%lf %lf %lf", &x, &y, &r)) != 3)
        {
            k = 1;
            break;
        }

        if(n == 0)
        {
            this->head = new Circle(x, y, r, 0);
            this->cur = head;
            n++;
        }
        else
        {
            Circle* tmp = new Circle(x, y, r, n);
            this->cur->pNext = tmp;
            this->cur = tmp;
            this->cur->pNext = nullptr;
            n++;
            tmp = nullptr;
        }

        if (feof(fin))
        {
            k = 1;
            break;
        }
    }

      if(!feof(fin))
      {
            printf("Not Enough Data or Bad Data");
            return -2;
      }

      if(n <= 1)
      {
          printf("Not Enough Data");
          return -3;
      }

    printf("%s %d %s\n", "We Have", n, "Circles");
    fclose(fin);
    this->k = n;
    return n;
}

void Circle::check(Circle* cir)
{
  if (x == cir->x && y == cir->y && r == cir->r)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Sovpadayut");
      return;
  }

  double R = this->r + cir->r;
  double Ro = sqrt(pow(this->x - cir->x, 2) + pow(this->y - cir->y, 2));

  if(Ro + r < cir->r || Ro + cir->r < r)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Ne Peresekayutsya, Odna Vnutri Drugoy");
  } else
  if ((Ro + r) - cir->r < Eps || (Ro + cir->r) - r < Eps)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Kasayutsya Vnutrennim Obrazom");
  } else
  if (fabs(R - Ro) < Eps)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Kasayutsya");
  } else if (Ro > R)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Ne Peresekayutsya");
  } else if (Ro < R)
  {
      printf("%s %d %s %d %s\n", "Circles ", this->k, " and ", cir->k, "Peresekayutsya");
  }

}

void Field::print()
{
    Circle* cur = head;
    while(cur)
    {
        printf("%.4f %.4f %.4f \n",cur->x, cur->y, cur->r);
        cur = cur->pNext;
    }
    printf("\n\n");
}

void Field::check()
{
    if (k == 1)
    return;

    cur = head;
    Circle* tmp = cur;
    while(cur->pNext != nullptr)
    {
        while(tmp->pNext)
        {
            cur->check(tmp->pNext);
            tmp = tmp->pNext;
        }
        cur = cur->pNext;
        tmp = cur;
    }
    printf("\n\n");
}
