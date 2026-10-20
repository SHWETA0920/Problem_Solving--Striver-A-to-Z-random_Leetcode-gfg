SELECT p. product_name as  product_name,
SUM(o.unit) AS unit
FROM Orders as o inner join Products as p
on p.product_id=o.product_id
WHERE o.order_date >= '2020-02-01'
  AND o.order_date < '2020-03-01'
GROUP BY o.product_id having sum(o.unit)>=100;