import React, { useState } from "react";
import "./Table.css"

const Catalog = () => {
  const [sortedBy, setSortedBy] = useState("isNew");
  const [sortDirection, setSortDirection] = useState("desc");
  const [searchQuery, setSearchQuery] = useState("");
  const [searchType, setSearchType] = useState("exact");

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

  const handleSort = (columnName) => {
    if (columnName === sortedBy) {
      setSortDirection(sortDirection === "asc" ? "desc" : "asc");
    } else {
      setSortedBy(columnName);
      setSortDirection("asc");
    }
  };

  const handleSearch = (query, type) => {
    setSearchQuery(query);
    setSearchType(type);
  };

  const renderProducts = () => {
    let sortedProducts = [...products];

    if (sortedBy === "isNew") {
      sortedProducts.sort((a, b) => (a.isNew ? -1 : 1));
    } else if (sortedBy === "price") {
      sortedProducts.sort((a, b) => a.price - b.price);
    } else if (sortedBy === "stock") {
      sortedProducts.sort((a, b) => a.stock - b.stock);
    } else if (sortedBy === "name") {
      sortedProducts.sort((a, b) => a.name.localeCompare(b.name));
    }

    if (sortDirection === "desc") {
      sortedProducts.reverse();
    }

    let filteredProducts = sortedProducts;

    if (searchQuery !== "") {
      if (searchType === "exact") {
        filteredProducts = sortedProducts.filter(
          (product) => product.name.toLowerCase() === searchQuery.toLowerCase()
        );
      } else if (searchType === "partial") {
        filteredProducts = sortedProducts.filter((product) =>
          product.name.toLowerCase().includes(searchQuery.toLowerCase())
        );
      }
    }

    return filteredProducts.map((product) => {
      let stockColor = "";
      if (product.stock === 0) {
        stockColor = "red";
      } else if (product.stock < 3) {
        stockColor = "yellow";
      }
      const discountedPrice = product.price * (1 - product.discount / 100);

      return (
        <div key={product.id} className="product">
          <div className="product-image">
            <img src={product.image} alt={product.name} className="product-thumbnail" />
          </div>
          <div className="product-details">
            <h3 className="product-name">{product.name}</h3>
            <p className="product-description">{product.description}</p>
            {product.isNew && <span className="product-tag new">New</span>}
            <div className="product-price">
              {product.discount > 0 && (
                <span className="product-discounted-price">${discountedPrice.toFixed(2)}</span>
              )}
              <span className="product-original-price">${product.price.toFixed(2)}</span>
            </div>
            <div className="product-stock" style={{ backgroundColor: stockColor }}>
              {product.stock > 0 ? "In Stock" : "Out of Stock"}
            </div>
          </div>
        </div>
      );
    });
  };

  return (
    <div className="catalog">
      <h2 className="catalog-heading">Catalog</h2>
      <div>
        <input
          type="text"
          value={searchQuery}
          onChange={(e) => setSearchQuery(e.target.value)}
          placeholder="Search by product name"
        />
        
      </div>
      <div className="catalog-sort">
        <span className="sort-label">Sort by:</span>
        <button className="sort-button" onClick={() => handleSort("name")}>
          Name
        </button>
        <button className="sort-button" onClick={() => handleSort("price")}>
          Price
        </button>
        <button className="sort-button" onClick={() => handleSort("stock")}>
          Stock
        </button>
        <button className="sort-button" onClick={() => handleSort("isNew")}>
          New
        </button>
      </div>
      <div className="catalog-products">{renderProducts()}</div>
    </div>
  );
};

export default Catalog;
