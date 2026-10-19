SELECT product_id, year AS first_year, quantity, price
FROM (
    SELECT product_id, year, quantity, price,
           DENSE_RANK() OVER (
               PARTITION BY product_id
               ORDER BY year ASC
           ) AS rnk
    FROM Sales
) AS sale
WHERE rnk = 1;