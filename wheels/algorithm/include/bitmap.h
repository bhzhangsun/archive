#ifndef _ZSBH_BITMAP_H_
#define _ZSBH_BITMAP_H_

#include <cstring>
namespace zsbh {

class bitmap
{
public:
	typedef unsigned int uint;
	typedef unsigned char uchar;

	bitmap(uint init_size = 1024) : size(init_size)
	{
		//不可重入
		buff = new char[init_size];
		memset(buff, 0, size);
	}

	~bitmap() { delete[] buff; }

	int get(uint pos)
	{
		uchar offset = pos % 8;
		uint idx = pos / 8;
		if (idx >= size)
			return -1;
		else
			return (buff[idx] >> (7 - offset)) & 0x01;
	}

	int set(uint pos) //set 1
	{
		uchar offset = pos % 8;
		uint idx = pos / 8;
		//idx > size resize;
		while (idx >= size)
		{
			if (-1 == resize())
				return -1;
		}			
		buff[idx] |= (0x01 << (7 - offset));
		return 0;
	}
private:
	int resize()
	{
		uint src_size = size;
		if (size * 2 - 0x11111111 > 0)
		{
			return -1;
		}

		size *= 2;
		char *tmp = new char[size];
		memcpy(buff, tmp, src_size);
		memset(tmp + src_size, 0, src_size);
		delete[] buff;
		buff = tmp;
		return 0;
	}

	char *buff;
	uint size;
};

}
#endif // !_ZSBH_BITMAP_H_
