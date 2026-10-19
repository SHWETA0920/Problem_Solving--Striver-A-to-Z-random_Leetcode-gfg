SELECT p.employee_id AS employee_id,
       p.name,
       p.re AS reports_count,
       p.ave AS average_age
FROM (
    SELECT e2.employee_id, e2.name,
           COUNT(*) AS re,
           ROUND(AVG(e1.age)) AS ave
    FROM employees e1
    JOIN employees e2
        ON e1.reports_to = e2.employee_id
    GROUP BY e2.employee_id, e2.name
) AS p  order by p.employee_id;