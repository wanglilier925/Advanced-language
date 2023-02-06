// copyright 2022 lili wang

#include <exam2/inc/functional_array.h>

#include <cstddef>
::size_t** Allocate(const ::size_t* sizes, ::size_t length)
{
	::size_t** delete_me = new ::size_t*[length];
	   
	for(size_t i = 0; i < length; i++)
	{
		delete_me[i] = new size_t[sizes[i]];
		for(size_t j = 0; j < sizes[i]; j++)
			{
				delete_me[i][j] = sizes[i];
			}
	}
	return delete_me;
}

// sum the array numbers

::size_t Deallocate(const ::size_t** delete_me,
                    const ::size_t* sizes,
                    ::size_t length){
::size_t sum = 0;
for( size_t i = 0; i < length; i++){
	for(size_t j = 0; j < sizes[i]; j++)
		sum += delete_me[i][j];
}

for (size_t i = 0; i < length; i++) {
    delete[] delete_me[i];
  }
delete[] delete_me;
return sum;

}