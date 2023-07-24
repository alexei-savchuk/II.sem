import React, { useState } from "react";

const products = [
  { id: 1, name: "Butter", price: 0.9, stock: 99 },
  { id: 2, name: "Cheese", price: 4.9, stock: 20 },
  { id: 3, name: "Fancy French Cheese", price: 99, stock: 12 },
  { id: 4, name: "Heavy Cream", price: 3.9, stock: 2 },
  { id: 5, name: "Milk", price: 1.9, stock: 32 },
  { id: 6, name: "Sour Cream", price: 2.9, stock: 86 },
  { id: 7, name: "Yoghurt", price: 2.4, stock: 0 }
];

const SortTable = () => {
  const [sortedBy, setSortedBy] = useState("id"); // по умолчанию сортируем по id
  const [sortDirection, setSortDirection] = useState("asc"); // по умолчанию сортируем по возрастанию

  const handleSort = (columnName) => {
    if (columnName === sortedBy) {
      // если уже сортируем по этому столбцу, меняем направление сортировки
      setSortDirection(sortDirection === "asc" ? "desc" : "asc");
    } else {
      // иначе сортируем по новому столбцу
      setSortedBy(columnName);
      setSortDirection("asc");
    }
  };

  const getSortedProducts = () => {
    return [...products].sort((a, b) => {
      const aValue = a[sortedBy];
      const bValue = b[sortedBy];
      if (sortedBy === "name") {
        // для сортировки по названию используем лексикографический порядок
        return sortDirection === "asc" ? aValue.localeCompare(bValue) : bValue.localeCompare(aValue);
      } else {
        // для сортировки по цене и количеству используем числовой порядок
        return sortDirection === "asc" ? aValue - bValue : bValue - aValue;
      }
    });
  };

  const renderProducts = () => {
    const sortedProducts = getSortedProducts();
    return sortedProducts.map((product) => {
      let stockColor = "";
      if (product.stock === 0) {
        stockColor = "red";
      } else if (product.stock < 3) {
        stockColor = "yellow";
      }
      return (
        <tr key={product.id}>
          <td>{product.id}</td>
          <td>{product.name}</td>
          <td>{`$${product.price.toFixed(2)}`}</td>
          <td style={{ backgroundColor: stockColor }}>{product.stock}</td>
        </tr>
      );
    });
  };

  return (
    <table className="my-table">
      <thead className="my-table__head">
        <tr>
          <th className="my-table__header" onClick={() => handleSort("id")}>
            #
          </th>
          <th className="my-table__header" onClick={() => handleSort("name")}>
            Name
          </th>
          <th className="my-table__header" onClick={() => handleSort("price")}>
            Price
          </th>
          <th className="my-table__header" onClick={() => handleSort("stock")}>
            In stock
          </th>
        </tr>
      </thead>
      <tbody className="my-table__body">{renderProducts()}</tbody>
    </table>
  );
};

export default SortTable;

