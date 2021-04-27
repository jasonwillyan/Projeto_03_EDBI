#ifndef PTIME_H
#define PTIME_H

#include <ostream>
#include <chrono>
#include <vector>

using namespace std::chrono;

/**
 * @brief Uma classe que simula um cronômetro fazendo o uso da biblioteca chrono de modo a tornar seu uso mais conveniente e legível.
 * 
 * @tparam cast - 
 */
template <class cast>
class ptime
{
private:
	std::vector<time_point<high_resolution_clock>> points;
	size_t current_point = 0;

public:
	/**
	 * @brief Construct a new ptime object
	 * 
	 */
	ptime()
	{}

	using time_iterator = typename std::vector<time_point<high_resolution_clock>>::iterator;

	/**
	 * @brief Retorna um iterador que aponta para o primeiro ponto do cronômetro.
	 * 
	 */
	time_iterator begin()
	{
		return this->points.begin();
	}
	
	/**
	 * @brief Retorna um iterador que aponta para o último ponto do cronômetro.
	 * 
	 */
	time_iterator end()
	{
		return this->points.end();
	}

	/**
	 * @brief Inicia a contagem do cronômetro.
	 * 
	 */
	void start()
	{
		this->current_point = 0;
		this->points.clear();
		this->points.emplace_back(this->now());
	}

	/**
	 * @brief Reinicia o cronômetro (equivalente à função start).
	 * 
	 */
	void restart()
	{
		this->start();
	}

	/**
	 * @brief Marca um ponto (volta) no cronômetro.
	 * 
	 * @return Retorna um tipo size_t referente ao número da volta atual.  
	 */
	size_t point()
	{
		current_point++;
		this->points.emplace_back(this->now());
		return this->current_point;
	}

	/**
	 * @brief Informa o tempo decorrido entre o ponto informado e o ponto anterior.
	 * 
	 * @param point 
	 * @return Retorna um tipo double referente ao tempo decorrido. 
	 */
	double elapsed(size_t point)
	{
		return duration_cast<cast>(this->points[point] - this->points[point - 1]).count();
	}

	/**
	 * @brief Informa o tempo decorrido entre o último ponto até então.
	 * 
	 * @return Retorna um tipo double referente ao tempo decorrido.
	 */
	double elapsed()
	{
		return duration_cast<cast>(this->now() - this->points[this->current_point]).count();
	}

	/**
	 * @brief Informa o tempo decorrido entre dois pontos do cronômetro.
	 * 
	 * @param size_t begin - Ponto inicial 
	 * @param size_t end - Ponto final 
	 * @return Retorna um tipo double referente ao tempo decorrido.
	 */
	double between(size_t begin, size_t end)
	{
		return duration_cast<cast>(this->points[end] - this->points[begin]).count();
	}

	/**
	 * @brief Informa o tempo decorrido desde o início da contagem até então.
	 * 
	 * @return Retorna um tipo double referente ao tempo decorrido.
	 */
	double total()
	{
		return duration_cast<cast>(this->points[current_point] - this->points[0]).count();
	}

	time_point<high_resolution_clock> now()
	{
		return high_resolution_clock::now();
	}
};

#endif