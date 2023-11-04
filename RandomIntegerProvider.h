#pragma once

class RandomIntegerProvider {
private:
	inline static bool _seeded = false;
public:
	RandomIntegerProvider();

	/// <summary>
	/// SInh số ngẫu nhiên trong đoạn [0, 4 tỉ)
	/// </summary>
	/// <returns>Số ngẫu nhiên</returns>
	int next();

	
	/// <summary>
	/// Sinh số ngẫu nhiên trong đoạn [0, max)
	/// </summary>
	/// <param name="max">Giá trị tối đa</param>
	/// <returns>Số nguyên</returns>
	int next(int max);

	/// <summary>
	/// Sinh số ngẫu nhiên trong đoạn [left, right]
	/// </summary>
	/// <param name="left">Biên trái</param>
	/// <param name="right">Biên phải</param>
	/// <returns>Số ngẫu nhiên [left, right]</returns>
	int next(int left, int right);
};