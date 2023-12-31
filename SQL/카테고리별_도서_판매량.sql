SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK, BOOK_SALES
WHERE SALES_DATE LIKE "2022-01-%" AND BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
GROUP BY CATEGORY
ORDER BY CATEGORY