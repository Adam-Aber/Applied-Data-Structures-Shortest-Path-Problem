#ifndef EDGE_H
#define EDGE_H

typedef int weightType;

class Edge
	   {
		public:
			int u;
			int v;
			weightType w;
			bool operator < (const Edge &e)
			{ return (w < e.w); }
			bool operator <= (const Edge &e)
			{ return (w <= e.w); }
            bool operator>(const Edge& other) const
            {return w > other.w;}

	   };
#endif // EDGE_H

