#pragma once

#include "tajo_status.h"
#include "tajo_buffer.h"
// A batch of zero or more rows returned from a TajoClient.
//
// With C++11, you can iterate over the rows in the batch using a
// range-foreach loop:
//
//   for (ResultBatch::Row row : batch) {
//     ... row.GetInt(1, ...)
//     ...
//   }
//
// In C++03, you'll need to use a regular for loop:
//
//   for (int i = 0, num_rows = batch.NumRows();
//        i < num_rows;
//        i++) {
//     ResultBatch::Row row = batch.Row(i);
//     ...
//   }
class ResultBatch {
public:
	class Row;

	class const_iterator;

	// Return the number of rows in this batch.
	int NumRows() const;

	// Return a reference to one of the rows in this batch.
	// The returned object is only valid for as long as this ResultBatch.
	ResultBatch::Row Get(int idx) const;

	const_iterator begin() const;

	const_iterator end() const;
};

// A single row result from a ResultBatch. Note that this object acts as a pointer into
// a ResultBatch, and therefore is valid only as long as the batch it was constructed
// from.
class ResultBatch::Row {

public:

	class TajoValue;
	bool IsNull(const std::string &col_name) const;

	bool IsNull(int col_idx) const;

	// These getters return a bad Status if the type does not match,
	// the value is unset, or the value is NULL. Otherwise they return
	// the current set value in *val.
	TajoStatus GetBool(const std::string &col_name, bool *val) const;

	TajoStatus GetInt8(const std::string &col_name, boost::int8_t *val) const;

	TajoStatus GetInt16(const std::string &col_name, boost::int16_t *val) const;

	TajoStatus GetInt32(const std::string &col_name, boost::int32_t *val) const;

	TajoStatus GetInt64(const std::string &col_name, boost::int64_t *val) const;

	TajoStatus GetTimestamp(const std::string &col_name,
		int64_t *millisecs_in_julian_time) const;

	TajoStatus GetFloat(const std::string &col_name, float *val) const;

	TajoStatus GetDouble(const std::string &col_name, double *val) const;

	// Same as above getters, but with numeric column indexes.
	// These are faster since they avoid a hashmap lookup, so should
	// be preferred in performance-sensitive code.
	TajoStatus GetBool(int col_idx, bool *val) const;

	TajoStatus GetInt8(int col_idx, int8_t *val) const;

	TajoStatus GetInt16(int col_idx, int16_t *val) const;

	TajoStatus GetInt32(int col_idx, int32_t *val) const;

	TajoStatus GetInt64(int col_idx, int64_t *val) const;

	TajoStatus GetTimestamp(int col_idx, int64_t *millisecs_in_julian_time) const;

	TajoStatus GetFloat(int col_idx, float *val) const;

	TajoStatus GetDouble(int col_idx, double *val) const;

	// Gets the string/binary value but does not copy the value. Callers should
	// copy the resulting Slice if necessary.
	TajoStatus GetString(const TajoSlice &col_name, TajoSlice *val) const;

	TajoStatus GetString(int col_idx, TajoSlice *val) const;

	// Destroy all resources and connection
	TajoStatus close();

private:
	friend class ResultBatch;
};

// C++ forward iterator over the rows in a ResultBatch.
//
// This iterator yields ResultBatch::Row objects which point inside the row batch
// itself. Thus, the iterator and any objects obtained from it are invalidated if the
// ResultBatch is destroyed or after ResultBatch::close() call.
class ResultBatch::const_iterator
	: public std::iterator<std::forward_iterator_tag, ResultBatch::Row>{
public:
	~const_iterator() { }

	ResultBatch::Row operator*() const {
		return batch_->Get(idx_);
	}

	void operator++() {
		idx_++;
	}

	bool operator==(const const_iterator &other) {
		return idx_ == other.idx_;
	}

	bool operator!=(const const_iterator &other) {
		return idx_ != other.idx_;
	}

private:
	friend class ResultBatch;

	const_iterator(const ResultBatch *b, int idx)
		: batch_(b),
		idx_(idx) {
	}

	const ResultBatch *batch_;
	int idx_;
};

inline ResultBatch::const_iterator ResultBatch::begin() const {
	return const_iterator(this, 0);
}

inline ResultBatch::const_iterator ResultBatch::end() const {
	return const_iterator(this, NumRows());
}
