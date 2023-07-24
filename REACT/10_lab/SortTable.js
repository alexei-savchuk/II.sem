import React, { useState } from "react";


const products = [
  {
    id: 1,
    name: "ButterГриль GoGarden Chef-Master 69",
    price: 251.24,
    stock: 20,
    image: "/catalog/product1.png",
    description: "гриль-решетка, сталь, крышка, столики, полка для дров (принадлежностей), колеса, 52x98x114 см",
    isNew: false,
    discount: 10,
  },
  {
    id: 2,
    name: "Складной мангал Perfecto Linea 47-135272",
    price: 17.94,
    stock: 40,
    image: "/catalog/product2.png",
    description: "гриль-решетка, сталь (0.4 мм), 27x35x20 см",
    isNew: true,
    discount: 0,
  },
  {
    id: 3,
    name: "Разборный мангал Perfecto Linea 47-750049",
    price: 4.9,
    stock: 60,
    image: "/catalog/product3.png",
    description: "сталь, 40x25x40 см",
    isNew: true,
    discount: 0,
  },
  {
    id: 4,
    name: "Гриль BoyScout 61250",
    price: 27.29,
    stock: 20,
    image: "/catalog/product4.png",
    description: "гриль-решетка, сталь с жаропрочной эмалью, 35.5x35.5x53 см.",
    isNew: false,
    discount: 12,
  },
  {
    id: 5,
    name: "Гриль GoGarden Chef-Master 66",
    price: 228.18,
    stock: 0,
    image: "/catalog/product5.png",
    description: "гриль-решетка, сталь, крышка, столики, полка для дров (принадлежностей), колеса, 46x77x114 см",
    isNew: false,
    discount: 0,
  },
  {
    id: 6,
    name: "Мангал для дачи Progrill Чикаго вуд (4 мм)",
    price: 127.75,
    stock: 17,
    image: "/catalog/product6.png",
    description: "сталь с жаропрочной эмалью (4 мм), крышка, столики, полка для дров (принадлежностей), 134x38x93 см",
    isNew: true,
    discount: 10,
  },
  {
    id: 7,
    name: "Гриль Zaria SK29A",
    price: 141.76,
    stock: 25,
    image: "/catalog/product7.png",
    description: "гриль-решетка, сталь (1.3 мм), столики, полка для дров (принадлежностей), колеса, 101x70.5x94.5 см",
    isNew: false,
    discount: 0,
  },
  {
    id: 8,
    name: "Гриль Fieldmann FZG 1030G",
    price: 174.3,
    stock: 20,
    image: "/catalog/product8.png",
    description: "гриль-решетка, искусственный камень, 60x60x42 см",
    isNew: true,
    discount: 10,
  },
  
];

export const getSortedProducts = (sortedBy, sortDirection) => {
  return [...products].sort((a, b) => {
    const aValue = a[sortedBy];
    const bValue = b[sortedBy];
    if (sortedBy === "name") {
      return sortDirection === "asc" ? aValue.localeCompare(bValue) : bValue.localeCompare(aValue);
    } else if (sortedBy === "discount" || sortedBy === "isNew") {
      return sortDirection === "asc" ? aValue - bValue : bValue - aValue;
    } else {
      return sortDirection === "asc" ? aValue - bValue : bValue - aValue;
    }
  });
};

const SortTable = () => {
  const [sortedBy, setSortedBy] = useState("id");
  const [sortDirection, setSortDirection] = useState("asc");

  const handleSort = (columnName) => {
    if (columnName === sortedBy) {
      setSortDirection(sortDirection === "asc" ? "desc" : "asc");
    } else {
      setSortedBy(columnName);
      setSortDirection("asc");
    }
  };

  const renderProducts = () => {
    const sortedProducts = getSortedProducts(sortedBy, sortDirection);
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
          <td>{`${product.price.toFixed(2)}`}</td>
          <td style={{ backgroundColor: stockColor }}>{product.stock}</td>
          <td>
            <img src={product.image} alt={product.name} className="product-thumbnail" />
          </td>
          <td>{product.description}</td>
          <td>{product.isNew ? "Да" : "Нет"}</td>
          <td>{product.discount}%</td>
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
          <th className="my-table__header" onClick={() => handleSort("image")}>
            Image
          </th>
          <th className="my-table__header" onClick={() => handleSort("description")}>
            Description
          </th>
          <th className="my-table__header" onClick={() => handleSort("isNew")}>
            New
          </th>
          <th className="my-table__header" onClick={() => handleSort("discount")}>
            Discount
          </th>
        </tr>
      </thead>
      <tbody className="my-table__body">{renderProducts()}</tbody>
    </table>
  );
};

export default SortTable;
